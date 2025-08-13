class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<vector<int>>q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push({0,0,0});
        visited[0][0]=true;
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        while(!q.empty()){
            vector<int> temp=q.front();
            q.pop();
            int x=temp[0];
            int y=temp[1];
            int d=temp[2];
            if(x==n-1 && y==n-1) return d+1;
            for(vector<int> &v:directions){
                int nx=x+v[0];
                int ny=y+v[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]==0){
                    q.push({nx,ny,d+1});
                    visited[nx][ny]=true;
                }
            }
        }
        return -1;


        
    }
};