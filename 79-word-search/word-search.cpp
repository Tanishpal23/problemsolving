class Solution {
public:
    int n, m;
    int k;

    vector<int> dirX = { -1, 0, 1, 0 };
    vector<int> dirY = { 0, 1, 0, -1 };

    bool dfs( int row, int col, int curr, vector<vector<char>>& board, string word ){
        if( curr == k-1 )return true;

        char temp = board[row][col];
        board[row][col] = '#';

        for( int i=0; i<4; i++ ){
            int newR = row + dirX[i];
            int newC = col + dirY[i];

            if( newR>=0 && newR<n && newC>=0 && newC<m && board[newR][newC] == word[curr+1] ){
                if( dfs( newR, newC, curr+1, board, word ) ) return true;
            }

        }

        board[row][col] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();
        k = word.size();

        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){

                if( word[0] == board[i][j] ){
                    if( dfs(i, j, 0, board, word) ) return true;
                }

            }
        }

        return false;
    }
};