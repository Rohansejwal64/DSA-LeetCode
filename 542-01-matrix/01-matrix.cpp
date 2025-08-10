class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> ans(r, vector<int>(c, -1));
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    // Initialize with all 0 cells
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(mat[i][j] == 0) {
                ans[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for(auto &d : directions) {
            int nx = x + d[0], ny = y + d[1];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && ans[nx][ny] == -1) {
                ans[nx][ny] = ans[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return ans;
}

};