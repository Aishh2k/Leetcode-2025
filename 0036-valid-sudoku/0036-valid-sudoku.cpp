class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<int> stRow;
            unordered_set<int> stCol;
            unordered_set<int> stBox;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (stRow.count(board[i][j])) {
                        return false;
                    } else {
                        stRow.insert(board[i][j]);
                    }
                }

                if (board[j][i] != '.') {
                    if (stCol.count(board[j][i])) {
                        return false;
                    } else {
                        stCol.insert(board[j][i]);
                    }
                }
                int Rstart = (i/3) *3;
                int Cstart = (i%3) *3;

                if (board[Rstart + (j/3)][Cstart + (j%3)] != '.') {
                    if (stBox.count(board[Rstart + (j/3)][Cstart + (j%3)])) {
                        return false;
                    } else {
                        stBox.insert(board[Rstart + (j/3)][Cstart + (j%3)]);
                    }
                }
            }
            stRow.clear();
            stCol.clear();
            stBox.clear();
        }

        return true;
    }
};