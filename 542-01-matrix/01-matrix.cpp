class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});

                }
            }
        }
        vector<vector<int>> ans(r,vector<int>(c,0));
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto cell=q.front();
            q.pop();
            int x=cell.first.first;
            int y=cell.first.second;
            int dist=cell.second;
            visited[x][y]=true;
            for(vector<int> &d: directions){
                int nx=x+d[0];
                int ny=y+d[1];
                if((nx>=0 && nx<r && ny>=0 && ny<c) && !visited[nx][ny] && mat[nx][ny]==1){
                    ans[nx][ny]=dist+1;
                    q.push({{nx,ny},dist+1});
                    visited[nx][ny]=true;
                }


            }
        }
        return ans;
        
        
    }
};