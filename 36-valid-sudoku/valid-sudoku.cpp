class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (j != col && board[row][j] == dig)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == dig)
                return false;
        }

        // Check 3x3 box
        int stRow = (row / 3) * 3;
        int stCol = (col / 3) * 3;

        for (int i = stRow; i < stRow + 3; i++) {
            for (int j = stCol; j < stCol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == dig)
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                if (!isSafe(board, i, j, board[i][j]))
                    return false;
            }
        }

        return true;
    }
};