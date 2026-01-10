// Approach
// dp[i][j] = minimum ascii delete sum to make s1[0....i-1] and s2[0....j-1]

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        // dp[i][j] = minimum ASCII delete sum to make
        // s1[0..i-1] and s2[0..j-1] equal
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base cases
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];

        for (int j = 1; j <= m; j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        // fill dp
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        dp[i - 1][j] + s1[i - 1],  // delete from s1
                        dp[i][j - 1] + s2[j - 1]   // delete from s2
                    );
                }
            }
        }

        return dp[n][m];
    }
};
