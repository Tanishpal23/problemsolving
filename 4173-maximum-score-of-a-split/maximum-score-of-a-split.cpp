// Approach
// Precompute suffixMin for every index
// Start from left calculate sum, if sum > ans.. update ans

class Solution {
public:
    long long maximumScore(vector<int>& nums) {

        int n = nums.size();

        long long ans = INT_MIN;
        long long prefixSum = 0;
        vector<int> suffixMin(n, INT_MAX);

        int mini = nums[n-1];
        for(int i=n-1; i>=0; i--){
            mini = min(mini, nums[i]);
            suffixMin[i] = mini;
        }

        for(int i=0; i<n-1; i++){
            prefixSum += (nums[i]-suffixMin[i+1]);
            if( prefixSum > ans ){
                ans = prefixSum;
            }
            prefixSum += suffixMin[i+1];
        }

        return ans;

    }
};