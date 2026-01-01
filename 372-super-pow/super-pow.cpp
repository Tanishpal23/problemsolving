class Solution {
public:
    static const int MOD = 1337;

    int power(int a, int b) {
        int res = 1;
        a %= MOD;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int d : b) {
            res = power(res, 10);
            res = (res * power(a, d)) % MOD;
        }
        return res;
    }
};
