//approach
//1. Find index of negative number
//2. Expand left and right side to calculate minimum ans required

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();

        int ind = 0;
        while (ind < n && balance[ind] >= 0) ind++;

        if (ind == n) return 0;

        long long req = -balance[ind];
        long long ans = 0;

        int l = (ind - 1 + n) % n;
        int r = (ind + 1) % n;

        while (req > 0) {
            // take from left
            if (balance[l] > 0) {
                long long take = min((long long)balance[l], req);
                int d = min(abs(ind - l), n - abs(ind - l));
                ans += take * d;
                req -= take;
                balance[l] = 0;
            }

            // take from right
            if (req > 0 && balance[r] > 0) {
                long long take = min((long long)balance[r], req);
                int d = min(abs(ind - r), n - abs(ind - r));
                ans += take * d;
                req -= take;
                balance[r] = 0;
            }

            l = (l - 1 + n) % n;
            r = (r + 1) % n;

            // full cycle done and still req left → impossible
            if (l == (ind - 1 + n) % n && r == (ind + 1) % n && req > 0)
                return -1;
        }

        return ans;
    }
};