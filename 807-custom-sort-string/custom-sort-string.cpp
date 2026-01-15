class Solution {
public:
    string customSortString(string order, string s) {
        int n1 = order.size();
        int n2 = s.size();

        string ans = "";

        vector<int> freqS(26, 0);

        for (auto k : s) 
            freqS[k - 'a']++;

        for (auto k : order) {
            while (freqS[k - 'a'] > 0) {
                ans += k;
                freqS[k - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freqS[i] > 0) {
                ans += string(freqS[i], char(i + 'a'));
            }
        }

        return ans;
    }
};
