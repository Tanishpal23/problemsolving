// Approach
// Take all combination possible nodeA, nodeB
// If nodeA and nodeB are connected subtract 1.
// Note - nodeA and nodeB need not to be directly connected.

// TC O(n^2 + roads)
// SC O(n^2)

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));

        // build degree + direct connection info
        for (auto &road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = connected[v][u] = true;
        }

        int ans = 0;

        // check ALL city pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int rank = degree[i] + degree[j];
                if (connected[i][j]) rank--;

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};
