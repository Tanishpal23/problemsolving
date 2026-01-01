// Approach 
// Brute force

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                ans+=__builtin_popcount(nums[i]^nums[j]); 
            }
        }

        return ans;
    }
};