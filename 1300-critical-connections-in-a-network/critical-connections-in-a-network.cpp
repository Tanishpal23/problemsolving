// Approach (in your style)
// This is a graph bridge finding problem. A connection is critical if removing it disconnects the graph.

// We use DFS + timestamps (Tarjan’s Algorithm)

// During DFS:
// 1. timeIn[u] → time when node u is first visited
// 2. lowT[u] → earliest discovery time reachable from u
// 3. For an edge u -> v:
// After DFS of v
// If lowT[v] > timeIn[u]
// v cannot reach u or any ancestor
// So this edge is the only connection
// Hence, it is a critical connection (bridge)

// Back-edge case:
// If a node is already visited and is not parent
// Update lowT using timeIn (not lowT)


// TC O(n+m) n-nodes, m-edges
// SC O(n+m)

class Solution {
private:
    int timer = 1;

private:
    void dfs(int node, int parent,
             vector<vector<int>>& adjList,
             int timeIn[], int lowT[],
             vector<int>& vis,
             vector<vector<int>>& bridges) {

        // mark current node as visited
        vis[node] = 1;

        // initialize discovery time and low time
        timeIn[node] = lowT[node] = timer;
        timer++;

        // explore all adjacent nodes
        for (auto it : adjList[node]) {

            // ignore the edge to parent
            if (it == parent) continue;

            // if adjacent node is not visited
            if (vis[it] == 0) {

                dfs(it, node, adjList, timeIn, lowT, vis, bridges);

                // update low time after returning from DFS
                lowT[node] = min(lowT[node], lowT[it]);

                // bridge condition
                if (lowT[it] > timeIn[node]) {
                    bridges.push_back({node, it});
                }
            }
            else {
                // back-edge case
                // update low time using discovery time
                lowT[node] = min(lowT[node], timeIn[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // graph representation using adjacency list
        vector<vector<int>> adjList(n);

        for (auto connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // visited array
        vector<int> vis(n, 0);

        // discovery time and low time arrays
        int timeIn[n];
        int lowT[n];

        // stores all critical connections
        vector<vector<int>> bridges;

        // start DFS from node 0
        dfs(0, -1, adjList, timeIn, lowT, vis, bridges);

        return bridges;
    }
};
