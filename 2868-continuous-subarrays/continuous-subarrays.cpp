//Approach
// 1. Use sliding window with two monotonic deques
// mx → decreasing deque (front = maximum)
// mn → increasing deque (front = minimum)
// 2. Expand window with r
// 3. If max - min > 2, shrink from left
// 4. For every valid window [l..r],
// all subarrays ending at r are valid → add (r - l + 1)

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        int n = nums.size();
        deque<int> mx, mn;
        long long ans = 0;
        int l = 0;

        for(int r = 0; r < n; r++) {

            // maintain max deque (decreasing)
            while(!mx.empty() && nums[mx.back()] < nums[r])
                mx.pop_back();
            mx.push_back(r);

            // maintain min deque (increasing)
            while(!mn.empty() && nums[mn.back()] > nums[r])
                mn.pop_back();
            mn.push_back(r);

            // shrink window if invalid
            while(nums[mx.front()] - nums[mn.front()] > 2) {

                if(mx.front() == l) mx.pop_front();
                if(mn.front() == l) mn.pop_front();
                l++;
            }

            // count valid subarrays ending at r
            ans += (r - l + 1);
        }

        return ans;
    }
};
