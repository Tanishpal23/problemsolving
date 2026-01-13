// Approach
// Hard Coded

// TC - O(n*m)
// SC - O(1)

// Observation
// Total no of dia = n+m-1
// Upper Dia -> i-1, j+1
// Lower Dia -> i+1, j-1
// i = ??
// j = ??


class Solution {

    vector<int> ans;
    int n, m;
    
    // Upper Dia
    void findLowerDia(int i, int j, vector<vector<int>>& mat){
        
        while( i>=0 && i<n && j>=0 && j<m ){
            ans.push_back( mat[i][j] );
            i += 1;
            j -= 1;
        }

        return;
    }
    
    // Lower Dia
    void findUpperDia(int i, int j, vector<vector<int>>& mat){
        
        while( i>=0 && i<n && j>=0 && j<m ){
            ans.push_back( mat[i][j] );
            i -= 1;
            j += 1;
        }

        return;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        n = (int)mat.size();
        m = (int)mat[0].size();

        int i=0, j=0;

        // Total no of diagonals
        for(int ind = 0; ind<n+m-1; ind++){

            if(ind & 1){
                // odd diagonal → down-left → start from top-most
                i = max(0, ind - (m - 1));
                j = ind - i;
                findLowerDia(i, j, mat);
            } else {
                // even diagonal → up-right → start from bottom-most
                i = min(n - 1, ind);
                j = ind - i;
                findUpperDia(i, j, mat);
            }

        }

        //ans
        return ans;
    }
};