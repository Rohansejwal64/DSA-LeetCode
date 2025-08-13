class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    // No path possible if start or end blocked
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

    vector<vector<int>> result(n, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;

    pq.push({0, {0, 0}}); // start distance 0 (edges)
    result[0][0] = 0;

    vector<pair<int,int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1},
        {-1,-1}, {-1,1}, {1,-1}, {1,1}
    };

    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        int x = v.second.first;
        int y = v.second.second;
        int d = v.first;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                grid[nx][ny] == 0) {
                if (d + 1 < result[nx][ny]) { // safe because d < INT_MAX
                    result[nx][ny] = d + 1;
                    pq.push({d + 1, {nx, ny}});
                }
            }
        }
    }

    return (result[n-1][n-1] == INT_MAX) ? -1 : result[n-1][n-1] + 1;
}

};