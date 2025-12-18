class Solution {
public:

    bool validChar(int row, int col, vector<vector<char>>& board, char valchar){
        for(int i=0, j=0; i<9&&j<9; i++, j++){
            if(board[row][j] == valchar) return false;
            if(board[i][col] == valchar) return false;

            int r1 = 3*(row/3) + i/3;
            int c1 = 3*(col/3) + i%3;

            if(board[r1][c1] == valchar) return false;
        }
        return true;
    }
    bool newBoard( vector<vector<char>>& board ){

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){

                    for(int k='1'; k<='9'; k++){
                        if( validChar(i, j, board, k) ){
                            board[i][j] = k;

                            if( newBoard(board) ) return true;

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        newBoard( board );
    }
};