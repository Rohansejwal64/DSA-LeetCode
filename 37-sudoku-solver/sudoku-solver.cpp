class Solution {
public:
bool isValid(vector<vector<char>>& board, int &row, int &col, char &ch) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == ch) return false;  // row check
        if (board[i][col] == ch) return false;  // col check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false; // 3x3 box
    }
    return true;
}

bool solve(vector<vector<char>>& board, int row, int col) {
    if (row == 9) return true; // all rows done

    if (col == 9) return solve(board, row + 1, 0); // move to next row

    if (board[row][col] != '.') return solve(board, row, col + 1); // skip filled cells

    for (char ch = '1'; ch <= '9'; ch++) {
        if (isValid(board, row, col, ch)) {
            board[row][col] = ch;
            if (solve(board, row, col + 1)) return true;
            board[row][col] = '.'; // backtrack
        }
    }
    return false; // no valid digit found
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board, 0, 0);
}
};