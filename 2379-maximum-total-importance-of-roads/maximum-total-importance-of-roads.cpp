// Approach
// Greeedy -> Give maximum val to Node with highest degree and so on
// Find Degree of each node.
// assign val from n to 1 decreasingly
// compuate total ans.

// TC - O(E + n*log n)
// SC - O(n)

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        //degree vector
        vector<int> deg(n, 0);

        //compute degree of each node
        for(auto road: roads){
            int u = road[0], v = road[1];
            deg[u]++;
            deg[v]++;
        }

        //sort degree vector descendingly
        sort(deg.rbegin(), deg.rend());

        long long ans = 0;


        for(int i=0; i<n; i++){

            //ans = deg (total edges) * val of each node (assigned greedily)
            ans += (1ll*deg[i]*(n-i));
        }

        //return ans
        return ans;
    }
};