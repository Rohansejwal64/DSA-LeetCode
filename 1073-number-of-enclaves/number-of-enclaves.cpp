class Solution {
public:


void dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int x, int y){
    visited[x][y]=true;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
     for (vector<int>& d : directions) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 &&
                ny < grid[0].size() && !visited[nx][ny] &&
                grid[nx][ny] == 1) {
                    dfs(grid,visited,nx,ny);
            }
        }




}
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        for(int i=0;i<c;i++){
            if(grid[0][i]==1 && !visited[0][i]){
                dfs(grid,visited,0,i);
            }
        }
        for(int i=0;i<c;i++){
            if(grid[r-1][i]==1 && !visited[r-1][i]){
                dfs(grid,visited,r-1,i);
            }
        }
        for(int i=0;i<r;i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(grid,visited,i,0);
            }
        }
        for(int i=0;i<r;i++){
            if(grid[i][c-1]==1 && !visited[i][c-1]){
                dfs(grid,visited,i,c-1);
            }
        }
        int count=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && !visited[i][j]) count++;
            }
        }
        return count;

        
    }
};