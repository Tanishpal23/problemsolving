class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        unordered_map<int, int> freq;

        // Step 1: Convert each word to bitmask and count frequency
        for (string &w : words) {
            int mask = 0;
            for (char c : w) {
                mask |= (1 << (c - 'a'));
            }
            // discard words with more than 7 unique letters
            if (__builtin_popcount(mask) <= 7) {
                freq[mask]++;
            }
        }

        vector<int> ans;

        // Step 2: For each puzzle
        for (string &p : puzzles) {
            int puzzleMask = 0;
            for (char c : p) {
                puzzleMask |= (1 << (c - 'a'));
            }

            int firstCharMask = 1 << (p[0] - 'a');
            int count = 0;

            // enumerate all submasks of puzzleMask
            for (int sub = puzzleMask; sub; sub = (sub - 1) & puzzleMask) {
                // must contain first letter
                if (sub & firstCharMask) {
                    if (freq.count(sub)) {
                        count += freq[sub];
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};
