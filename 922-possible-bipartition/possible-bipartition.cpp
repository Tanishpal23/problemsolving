// Approach
// Bipartite graph
// dislikes -> should have different colours.
// Make graph of dislikes -> assign different colours (group) to adjacent nodes

// TC: O(n + m)   (n = nodes, m = dislikes/edges)
// SC: O(n + m)

class Solution {
public:

    bool dfs(int node, int currGrp, vector<vector<int>>& adjList, vector<int>& grp) {

        // assign current group
        grp[node] = currGrp;

        // visit all neighbours
        for(auto neighbour : adjList[node]) {

            // if neighbour already assigned
            if(grp[neighbour] != -1) {
                // conflict: same group on both ends
                if(grp[neighbour] == currGrp)
                    return false;
            }
            // if neighbour not assigned, assign opposite group
            else {
                if(!dfs(neighbour, !currGrp, adjList, grp))
                    return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        // Graph initialisation in form of adjList
        vector<vector<int>> adjList(n+1);
        for(auto edge : dislikes) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // group assignment array
        vector<int> grp(n+1, -1);

        // check for all connected components
        for(int i = 1; i <= n; i++) {

            // if node not visited yet
            if(grp[i] == -1) {

                // start DFS with group 0
                if(!dfs(i, 0, adjList, grp))
                    return false;
            }
        }

        return true;
    }
};
