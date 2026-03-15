class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j , int idx, string word){
        if(idx == word.size()){
            return true;
        }

        if(i>=board.size() || j>= board[0].size() || i<0 || j<0 || board[i][j] != word[idx]){
            return false;
        }


        char temp = board[i][j];
        board[i][j] = '*';

        bool res = dfs(board,i+1,j,idx+1,word) || 
                    dfs(board,i,j+1,idx+1,word) ||
                    dfs(board,i-1,j,idx+1,word) ||
                    dfs(board,i,j-1,idx+1,word);

        board[i][j] = temp;

        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,0,word)){
                        return true;
                    }
                }
            }
        }

        return false;
        
    }
};