class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);

        for (char c : s)
            total[c - 'a']++;

        // impossible
        for (int i = 0; i < 3; i++)
            if (total[i] < k) return -1;

        vector<int> cnt(3, 0);
        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;

            while (cnt[0] > total[0] - k ||
                   cnt[1] > total[1] - k ||
                   cnt[2] > total[2] - k) {
                cnt[s[l] - 'a']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return n - maxLen;
    }
};
