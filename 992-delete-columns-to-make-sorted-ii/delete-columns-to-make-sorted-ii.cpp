//Approach 
//1. Traverse columns left → right
//2. Track which adjacent rows are already sorted
//3. If a column causes any unsorted pair to break order, delete it
//4. Otherwise, fix ordering for pairs where this column decides it

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n = strs.size();
        int m = strs[0].size();

        vector<bool> sorted(n - 1, false);
        int del = 0;

        for (int col = 0; col < m; col++) {

            bool bad = false;

            // check if this column breaks order
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            // if bad, delete this column
            if (bad) {
                del++;
                continue;
            }

            // update sorted pairs
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                    sorted[i] = true;
                }
            }
        }

        return del;
    }
};
