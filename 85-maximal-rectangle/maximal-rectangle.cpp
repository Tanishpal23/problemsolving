// Approach
// Consider each row a histogram and try finding this largest area in histogram
// Now preCompute the histogram column wise.

// TC-O(n*m) 
// SC-O(n*m)

class Solution {

    // stores histogram heights row-wise
    vector<vector<int>> preComputation;

    // next smaller element index   
    vector<int> nse;     

    // previous smaller element index                
    vector<int> pse;                     

    // Find Previous Smaller Element for each index
    void findPsee(vector<int>& heights, vector<int>& pse, int n) {
        stack<pair<int, int>> st; // {height, index}

        for(int i = 0; i < n; i++) {
            // Pop until smaller element is found
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();

            // If stack empty → no smaller element on left
            pse[i] = st.empty() ? -1 : st.top().second;

            st.push({heights[i], i});
        }
    }

    // Find Next Smaller Element for each index
    void findNse(vector<int>& heights, vector<int>& nse, int n) {
        stack<pair<int, int>> st; // {height, index}

        for(int i = n - 1; i >= 0; i--) {
            // Pop until smaller element is found
            while(!st.empty() && st.top().first > heights[i])
                st.pop();

            // If stack empty → no smaller element on right
            nse[i] = st.empty() ? n : st.top().second;

            st.push({heights[i], i});
        }
    }

    // Largest Rectangle Area in Histogram
    int findLargestAreaInHistogram(vector<int>& histogram) {
        int n = histogram.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            ans = max(ans, histogram[i] * width);
        }
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;

        preComputation.assign(n, vector<int>(m, 0));
        nse.assign(m, 0);
        pse.assign(m, 0);

        // Build histogram heights column-wise
        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += (matrix[i][j] - '0');
                if(matrix[i][j] == '0') sum = 0;
                preComputation[i][j] = sum;
            }
        }

        // For each row, solve Largest Rectangle in Histogram
        for(int i = 0; i < n; i++) {
            findPsee(preComputation[i], pse, m);
            findNse(preComputation[i], nse, m);

            int curr = findLargestAreaInHistogram(preComputation[i]);
            maxArea = max(maxArea, curr);
        }

        return maxArea;
    }
};
