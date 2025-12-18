class Solution {
public:
    bool isSafeToPlace(const vector<vector<char>>& board, int row, int col,
                       char digit) {
        // Check Horizontal
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == digit) {
                return false;
            }
        }

        // Check Vertical
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit) {
                return false;
            }
        }

        // Check 3x3 Sub-grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true; // Solved
        }

        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try placing digits 1-9
        for (char digit = '1'; digit <= '9'; digit++) {
            if (isSafeToPlace(board, row, col, digit)) {
                board[row][col] = digit;
                if (helper(board, nextRow, nextCol)) {
                    return true;
                }
                board[row][col] = '.'; // backtrack
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { helper(board, 0, 0); }
};