class Solution {
public:

    int n;
    vector<vector<int>> ans;

    void findPermutation( vector<int>& nums, int ind ){

        if( ind == n ){
            ans.push_back( nums );
            return;
        }
        for( int i=ind; i<n; i++ ){
            swap( nums[ind], nums[i] );
            findPermutation( nums, ind + 1 );
            swap( nums[ind], nums[i] );
        }

        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        findPermutation( nums, 0 );
        return ans;
    }
};