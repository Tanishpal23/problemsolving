//Approach
//1. always 1 element form smooth period
//2. expand the window (2pter) keep increasing answer.

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1;
        long long len = 1;

        for (int i = 1; i < n; i++) {
            if (prices[i-1] - prices[i] == 1) {
                len++;
            } else {
                len = 1;
            }
            ans += len;
        }

        return ans;
    }
};
