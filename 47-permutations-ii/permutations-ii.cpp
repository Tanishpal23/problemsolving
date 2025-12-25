class Solution {
public:
    set<vector<int>> stt1;
    vector<vector<int>> ans;

    void findPermuUsingSwap(int i, int n, vector<int>& nums){
        if(i==n){
            if(stt1.find(nums)==stt1.end()){
                ans.push_back(nums);
            }
            stt1.insert(nums);
            return;
        }

        for(int ind = i; ind<n; ind++){
            swap(nums[i], nums[ind]);
            findPermuUsingSwap(i+1, n, nums);
            swap(nums[i], nums[ind]);
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        findPermuUsingSwap(0, n, nums);
        return ans;
    }
};