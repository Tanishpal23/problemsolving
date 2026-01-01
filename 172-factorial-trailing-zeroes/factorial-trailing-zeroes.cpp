// Approach
// 1. only 2 and 5 will contribute towards ans
// 2. so we need to count no of 5...
// 3. 5->1....25->2....125->3
// 4. so for n we will count no of 5...
// 5. no of 5 = (n/5) + (n/25) + (n/125)....

class Solution {
public:
    int trailingZeroes(int n) {

        int ans = 0;
        while(n > 0){
            n /= 5;
            ans += n;
        }
        return ans;

    }
};