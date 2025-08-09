class Solution {
public:
bool safe(int row, int col, int r, int c) {
    return !(row < 0 || row >= r || col < 0 || col >= c);
}

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>> q;
    int r = grid.size();
    int c = grid[0].size();
    int fresh = 0;

    // Count fresh oranges and push rotten oranges into queue
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == 1) fresh++;
            if(grid[i][j] == 2) q.push({i,j});
        }
    }

    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int time = 0;

    while(!q.empty() && fresh > 0) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto &d : directions) {
                int newr = row + d[0];
                int newc = col + d[1];
                if(safe(newr, newc, r, c) && grid[newr][newc] == 1) {
                    grid[newr][newc] = 2;
                    q.push({newr, newc});
                    fresh--;
                }
            }
        }
        time++;
    }

    return (fresh == 0) ? time : -1;
}


};