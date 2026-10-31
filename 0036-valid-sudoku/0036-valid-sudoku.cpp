class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0;i<board.size();i++){
            unordered_set<int> rowWise;
            unordered_set<int> colWise;
            unordered_set<int> boxWise;
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] != '.'){
                    if(rowWise.count(board[i][j])){
                        return false;
                    }else{
                        rowWise.insert(board[i][j]);
                    }
                }

                if(board[j][i] != '.'){
                    if(colWise.count(board[j][i])){
                        return false;
                    }else{
                        colWise.insert(board[j][i]);
                    }
                }

                int rowStart = (i/3) * 3;
                int colStart =  (i%3) *3;

                if(board[rowStart + (j/3)][colStart + (j%3)] != '.'){
                    if(boxWise.count(board[rowStart + (j/3)][colStart + (j%3)])){
                        return false;
                    }else{
                        boxWise.insert(board[rowStart + (j/3)][colStart + (j%3)]);
                    }
                }
            }
        }
        return true;
    }
};