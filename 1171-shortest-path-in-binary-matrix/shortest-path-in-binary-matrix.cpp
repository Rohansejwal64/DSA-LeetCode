class Solution {
public:
   
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    // If start or end is blocked, no path exists
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<array<int, 3>> q; // {x, y, dist}

    q.push({0, 0, 1}); // distance starts at 1
    visited[0][0] = true;

    vector<pair<int,int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1},
        {-1,-1}, {-1,1}, {1,-1}, {1,1}
    };

    while (!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();

        if (x == n-1 && y == n-1) return dist;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
    }

    return -1; // no path found
}
};