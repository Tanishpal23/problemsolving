// Brute force

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> oneRow(n, 0);
        vector<int> oneCol(m, 0);

        for(int i=0; i<n; i++){

            for(int j=0; j<m; j++){
                
                int row = i;
                int col = j;

                if( grid[i][j] == 1 ){
                    oneRow[row]++;
                    oneCol[col]++;
                }
            }

        }

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int row = i;
                int col = j;
                ans[i][j] = oneRow[row] + oneCol[col] - (n-oneRow[row]) - (m-oneCol[col]);
            }
        }

        return ans;
    }
};