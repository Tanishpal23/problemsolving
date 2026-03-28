class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        int mini = INT_MAX;
        while( low<=high ){
            int mid = low + (high-low)/2;

            //if Both Sorted
            if( nums[low] < nums[mid] && nums[mid] < nums[high] ){
                mini = min( mini, nums[low] );
                return mini;
            }

            //if Right Sorted
            else if( nums[mid] < nums[high] ){
                mini = min( mini, nums[mid] );
                high = mid-1;
            }

            //if Left Sorted
            else{
                mini = min( mini, nums[low] );
                low = mid+1;
            }
        }

        return mini;
    }
};