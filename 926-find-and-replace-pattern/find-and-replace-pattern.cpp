class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (auto &w : words) {
            if (w.size() != pattern.size()) continue;

            vector<int> mp1(26, -1), mp2(26, -1);
            bool ok = true;

            for (int i = 0; i < w.size(); i++) {
                int a = w[i] - 'a';
                int b = pattern[i] - 'a';

                if (mp1[a] == -1 && mp2[b] == -1) {
                    mp1[a] = b;
                    mp2[b] = a;
                } else if (mp1[a] != b || mp2[b] != a) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans.push_back(w);
        }

        return ans;
    }
};
