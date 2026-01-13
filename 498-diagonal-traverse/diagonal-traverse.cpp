// Approach
// At every position where to go.
// for even i+j -> go upper right.
// for odd i+j -> go lower left.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = (int)mat.size();
        int m = (int)mat[0].size();

        vector<int> ans;
        int row = 0;
        int col = 0;

        for( int cnt=0; cnt < n*m; cnt++ ){
            
            ans.push_back( mat[row][col] );

            //important condition
            if((row + col) % 2 == 0){
                // up-right
                if(col == m - 1) row++;
                else if(row == 0) col++;
                else{
                    row--;
                    col++;
                }
            }
            else{
                // down-left
                if(row == n - 1) col++;
                else if(col == 0) row++;
                else{
                    row++;
                    col--;
                }
            }

        }

        return ans;
    }
};