class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            unordered_set<char> boxSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rowSet.count(board[i][j])) { // row by row check
                        return false;
                    } else {
                        rowSet.insert(board[i][j]);
                    }
                }
                if (board[j][i] != '.') {
                    if (colSet.count(board[j][i])) { // col by col check
                        return false;
                    } else {
                        colSet.insert(board[j][i]);
                    }
                }

                int boxRow = (i / 3) * 3 + (j / 3);
                int boxCol = (i % 3) * 3 + (j % 3);
                if (board[boxRow][boxCol] != '.') {
                    if (boxSet.count(
                            board[boxRow][boxCol])) { // box by box check
                        return false;
                    } else {
                        boxSet.insert(board[boxRow][boxCol]);
                    }
                }
            }
        }
        return true;
    }
};