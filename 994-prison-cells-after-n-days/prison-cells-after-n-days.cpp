// Approach
// Pata nhi

// Observation
// repeat krnge 14 iteration ke baad

// TC - O(14)
// SC - O((n%14)*8)

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

        //answer will repeat every 14th iteration
        n = (n % 14 == 0) ? 14 : n % 14;

        //check for only mod 14 iteration
        for (int j = 0; j < n; j++) {

            //next state storage
            vector<int> temp(cells.size(), 0);

            //assign value to next state (temp)
            for (int i = 1; i < cells.size() - 1; i++) {

                if (cells[i - 1] == cells[i + 1]) {
                    temp[i] = 1;
                }
            }

            //make next state = curr state for next iteration
            cells = temp;
        }

        //return ans
        return cells;
    }
};