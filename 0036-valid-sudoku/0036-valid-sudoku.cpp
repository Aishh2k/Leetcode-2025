class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0;i<board.size();i++){
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> box;

            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] != '.'){ // row wise check
                    if(row.count(board[i][j])){
                        return false;
                    }else{
                        row.insert(board[i][j]);
                    }
                }

                if(board[j][i] != '.'){ // col wise check
                    if(col.count(board[j][i])){
                        return false;
                    }else{
                        col.insert(board[j][i]);
                    }
                }

                // sub box wise checkchat
                int brow = (i/3) *3;
                int bcol = (i%3) *3;

                if(board[brow + (j/3)][bcol + (j%3)] != '.'){ // col wise check
                    if(box.count(board[brow + (j/3)][bcol + (j%3)])){
                        return false;
                    }else{
                        box.insert(board[brow + (j/3)][bcol + (j%3)]);
                    }
                }
            }
        }

        return true;
        
    }
};