class Solution {
public:
    bool dfs(int i, int j, int idx, string word, vector<vector<char>>& board){
        if(idx == word.size()){
            return true;
        }
        if(i>= board.size() || j>= board[0].size() || i<0 || j<0 || board[i][j] != word[idx]){
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '*';

        bool ret = dfs(i+1, j, idx+1, word, board) || dfs(i, j+1, idx+1, word, board) || dfs(i-1, j, idx+1, word, board) || dfs(i, j-1, idx+1, word, board);

        board[i][j] = c;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    bool ans = dfs(i, j, 0, word,board);
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/*
“We try every board cell as a possible starting point. From each cell, DFS explores up to four directions for each character of the word, giving roughly O(m*n*4^L) time. The recursion depth is at most the word length, so space is O(L).”*/
