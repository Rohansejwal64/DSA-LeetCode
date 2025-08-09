class Solution {
public:
bool safe(int row, int col, int r, int c){
    if(row<0 || row>=r || col<0 || col>=c) return false;
    return true;
}
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r=grid.size();
        int c=grid[0].size();
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;

                if(grid[i][j]==2) {
                    q.push({i,j});
                    
                }

            }
        }
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        int time=0;
        while(!q.empty() && fresh>0){
            int size=q.size();
            int check=0;
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(vector<int> &d:directions){
                    int newr=row+d[0];
                    int newc=col+d[1];
                    if(safe(newr,newc,r,c) && grid[newr][newc]==1){
                        grid[newr][newc]=2;
                        q.push({newr,newc});
                        fresh--;
                        check=1;
                    }

                }
            }
            if(check==1) time++;
        }
        if(fresh==0) return time;
        else{
            return -1;
        }

        
    }
};