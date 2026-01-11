// Approach
// Atlease 1 path exist between 1 and n.
// So do bfs/dfs for node 1.
// Take account of minimum.

// TC O(V+E)

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        //adjList 
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        //visited array
        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;

        //q for bfs/dfs traveral -> both will work.
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        //traversal
        while (!q.empty()) {
            int u = q.front(); q.pop();

            //bfs traversal to adjacent nodes
            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;
                
                //ans update
                ans = min(ans, w);

                //push unvisited nodes to queue
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        
        //return ans
        return ans;
    }
};
