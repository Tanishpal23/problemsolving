// Approach
// Check for all possible ans

class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> dp;

    bool solve(string curr) {
        if (curr.size() == 1) return true;
        if (dp.count(curr)) return dp[curr];

        string next = "";

        function<bool(int)> build = [&](int i) {
            if (i == curr.size() - 1)
                return solve(next);

            string key = curr.substr(i, 2);
            if (!mp.count(key)) return false;

            for (char ch : mp[key]) {
                next.push_back(ch);
                if (build(i + 1)) return true;
                next.pop_back();
            }
            return false;
        };

        return dp[curr] = build(0);
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return solve(bottom);
    }
};
