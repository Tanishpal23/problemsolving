class Solution {
public:
    int trap(vector<int>& nums) {
        
        int sz = nums.size();
        int left = 0;
        int leftMax = 0;
        int right = sz-1;
        int rightMax = 0;

        int ans = 0;

        while( left < right ){
            if( nums[left] > nums[right] ){
                if( rightMax > nums[right] ) ans += (rightMax-nums[right]);
                rightMax = max(rightMax, nums[right]);
                right--;
            }
            else{
                if( leftMax > nums[left] ) ans += (leftMax-nums[left]);
                leftMax = max(leftMax, nums[left]);
                left++;
            }
        }

        return ans;

    }
};