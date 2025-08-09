class Solution {
public:
void dfs(vector<vector<int>> &adj,vector<bool> &visited,int u){
    visited[u]=true;
    for(int &v: adj[u]){
        if(visited[v]==false){
            dfs(adj,visited,v);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                ans++;
            }
        }
        return ans;
        
    }
};