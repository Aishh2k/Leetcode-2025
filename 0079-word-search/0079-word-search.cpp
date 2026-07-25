class Solution {
public:
    bool dfs( int r, int c, int i, vector<vector<char>>& board,string word){
        if( i == word.size()){
            return true;
        }

        if(r<0 || c<0 || r == board.size() || c == board[0].size() || board[r][c] != word[i]){
            return false;
        }

        char C = board[r][c];
        board[r][c] = '*';
        
        bool res = dfs(r+1, c, i+1, board, word) || dfs(r, c+1, i+1, board, word) || dfs(r-1, c, i+1, board, word) || dfs(r, c-1, i+1, board, word);
        board[r][c] = C;
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans;
        for(int i =0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    ans = dfs(i, j, 0, board, word);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};