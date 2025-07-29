class Solution {
public:
    int rows[9], cols[9], boxes[9];
    vector<pair<int, int>> emptyCells;
    int getBoxIndex(int r, int c) { return (r / 3) * 3 + (c / 3); }

    bool solve(vector<vector<char>>& board, int idx) {
        if (idx == emptyCells.size())
            return true; // all filled

        int r = emptyCells[idx].first;
        int c = emptyCells[idx].second;
        int boxIdx = getBoxIndex(r, c);

        for (int num = 1; num <= 9; num++) {
            int mask = 1 << num;
            if (!(rows[r] & mask) && !(cols[c] & mask) &&
                !(boxes[boxIdx] & mask)) {
                // place number
                board[r][c] = num + '0';
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIdx] |= mask;

                if (solve(board, idx + 1))
                    return true;

                // backtrack
                board[r][c] = '.';
                rows[r] ^= mask;
                cols[c] ^= mask;
                boxes[boxIdx] ^= mask;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // initialize masks
        for (int i = 0; i < 9; i++) {
            rows[i] = cols[i] = boxes[i] = 0;
        }

        // fill masks and record empty cells
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0';
                    int mask = 1 << num;
                    rows[r] |= mask;
                    cols[c] |= mask;
                    boxes[getBoxIndex(r, c)] |= mask;
                } else {
                    emptyCells.push_back({r, c});
                }
            }
        }

        solve(board, 0);
    }
};