class Solution {
public:
    vector<vector<string>> res;
    bool isValid(vector<string>& board, int row,int col){
        int dupCol = col;
        int dupRow = row;

        while(row>0){ // vertically up
            row--;
            if(board[row][col] == 'Q'){
                return false;
            }
        }

        row = dupRow;
        while(row>0 && col <board.size()-1){// right diagnonal up
            row--;
            col++;
            if(board[row][col] == 'Q'){
                return false;
            }
        }
        row = dupRow;
        col = dupCol;
        while(row>0 && col>0){// left diagnonal up
            row--;
            col--;
            if(board[row][col] == 'Q'){
                return false;
            }
        }

        return true;
    }
    void solve(vector<string>& board, int row,int n){
        if(row ==n){
            res.push_back(board);
            return;
        }

        for(int col = 0; col<n;col++){
            if(isValid(board,row,col)){
                board[row][col] = 'Q';
                solve(board,row+1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0,n);
        return res;
    }
};