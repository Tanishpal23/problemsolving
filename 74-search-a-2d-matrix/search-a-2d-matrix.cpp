class Solution {
public: 
    int n, m;

    int findRow( vector<vector<int>>& matrix, int target ){

        int low = 0;
        int high = n-1;

        while( low <= high ){
            int mid = low + (high-low)/2;

            if( matrix[mid][0] <= target && matrix[mid][m-1] >= target ){
                return mid;
            }

            else if( matrix[mid][0] > target ) high = mid-1;
            
            else low = mid+1;

        }

        return -1;
    }

    int findCol( vector<vector<int>>& matrix, int target, int row ){
        int low = 0;
        int high = m-1;

        while( low<=high ){
            int mid = low + ( high-low )/2;
            
            if( matrix[row][mid] == target ) return mid;

            else if( matrix[row][mid] > target ) high = mid-1;

            else low = mid+1;
        }

        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        n = matrix.size();
        m = matrix[0].size();

        int row = findRow( matrix, target );

        if( row == -1 ) return false;

        int col = findCol( matrix, target, row );

        return col==-1? false: true;
    }
};