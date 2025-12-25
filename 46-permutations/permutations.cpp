class Solution {
public:

    vector<vector<int>> ans;

    void findPermuUsingSwap(int i, int n, vector<int>& nums){
        if(i==n){
            ans.push_back(nums);
            return;
        }

        for(int ind = i; ind<n; ind++){
            swap(nums[i], nums[ind]);
            findPermuUsingSwap(i+1, n, nums);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        findPermuUsingSwap(0, nums.size(), nums);

        return ans;
    }
};