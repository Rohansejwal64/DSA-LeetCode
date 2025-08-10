class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r,
             int c) {
        visited[r][c] = true;
        for (vector<int>& d : directions) {
            int nx = r + d[0];
            int ny = c + d[1];
            if (nx >= 0 && nx < board.size() && ny >= 0 &&
                ny < board[0].size() && !visited[nx][ny] &&
                board[nx][ny] == 'O') {
                    dfs(board,visited,nx,ny);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> pos;
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) &&
                    board[i][j] == 'O') {
                    pos.push_back({i, j});
                }
            }
        }
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i = 0; i < pos.size(); i++) {
            if (!visited[pos[i][0]][pos[i][1]]) {
                dfs(board, visited, pos[i][0], pos[i][1]);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};