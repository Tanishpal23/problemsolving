class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;

        sort(nums.begin(), nums.end());

        int maxi = 0;

        for(int i=0; i<m; i++){
            maxi = max(maxi, nums[i]+nums[n-i-1]);
        }

        return maxi;
    }
};