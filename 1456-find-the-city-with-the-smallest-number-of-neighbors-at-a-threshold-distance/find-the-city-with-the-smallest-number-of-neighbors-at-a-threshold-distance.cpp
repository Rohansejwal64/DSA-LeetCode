class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> result(n,vector<int>(n,INT_MAX));
        for(vector<int> &edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            result[u][v]=wt;
            result[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            result[i][i]=0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(result[i][via]!=INT_MAX && result[via][j]!=INT_MAX){
                        result[i][j]=min(result[i][j],result[i][via]+result[via][j]);
                    }
                }
            }
        }
        int mini=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(result[i][j]<=k){
                    count++;
                }

            }
            if(count<=mini){
                mini=count;
                ans=i;
            }
        }
        return ans;

        
    }
};