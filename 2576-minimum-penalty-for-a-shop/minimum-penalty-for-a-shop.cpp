// Approach
// 1. for each index pre compute no of 'N' from starting to that index
// 2. for each index pre compute no of 'Y' from that index to end
// 3. calculate penalty using the submission of both, take minimum.

//TC - O(n)+O(n)+O(n) = O(n)
//SC - O(n)+O(n) = O(n)

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> preN(n + 1, 0); // N from start to i
        vector<int> sufY(n + 1, 0); // Y from i to end

        // prefix count of 'N'
        for (int i = 0; i < n; i++) {
            preN[i + 1] = preN[i] + (customers[i] == 'N');
        }

        // suffix count of 'Y'
        for (int i = n - 1; i >= 0; i--) {
            sufY[i] = sufY[i + 1] + (customers[i] == 'Y');
        }

        int ans = 0;
        int minPenalty = INT_MAX;

        // calculate penalty for each closing time
        for (int i = 0; i <= n; i++) {
            int penalty = preN[i] + sufY[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};
