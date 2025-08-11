class Solution {
public:
vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited,int x, int y){
    visited[x][y]=true;
    for(vector<int> &d: directions){
        int nx=x+d[0];
        int ny=y+d[1];
        if((nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()) && grid[nx][ny]=='1' && !visited[nx][ny]){
            dfs(grid,visited,nx,ny);
        }
    }

}
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>> visited(r,vector<bool>(c,false));
         int count=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                   dfs(grid,visited,i,j);
                   count++;

                }
            }
        }
        return count;
       
        
        
    }
};