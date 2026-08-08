class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int idx){
        if(idx == word.size()){
            return true;
        }

        if(i>=board.size() || j>= board[0].size() || i<0 || j<0 || board[i][j] != word[idx]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '*';
        bool present = dfs(i+1,j, board,word, idx+1) || dfs(i,j+1, board,word, idx+1) || dfs(i,j-1, board,word, idx+1)
        || dfs(i-1,j, board,word, idx+1);

        board[i][j] = temp;

        return present;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int idx = 0;

        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(board[i][j] == word[idx]){
                    bool present = dfs(i,j,board,word, idx);
                    if(present){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};