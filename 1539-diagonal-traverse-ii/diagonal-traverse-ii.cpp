// Approach
// Same diagonal walo ke -> i+j equal hoga
// iterate through the whole nums
// store i+j, row, val.
// Now sort -> sorting will give lower index row before higher row index.
// So store n-i = row.

// TC - O(n*k log (n*k) )
// SC - O(n*k)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        int n = nums.size();
        //sum of i+j, row, val
        vector<vector<int>> tp;

        vector<int> ans;

        for(int i=0; i<n; i++){

            int m = nums[i].size();

            for(int j=0; j<m; j++){

                tp.push_back({i+j, n-i, nums[i][j]});

            }

        }


        sort(tp.begin(), tp.end());

        for(auto it: tp){
            ans.push_back( it[2] );
        }

        return ans;
    }
};