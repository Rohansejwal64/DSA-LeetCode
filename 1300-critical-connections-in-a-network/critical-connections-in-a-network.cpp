class Solution {
public:
void dfs(vector<vector<int>> &adj,vector<bool> &visited,vector<int> &tn,vector<int> &low,int &timer,vector<vector<int>> &ans,int u, int p){

    visited[u]=true;
    tn[u]=low[u]=timer;
    timer++;
    for(int &v:adj[u]){
        if(v==p) continue;
        if(!visited[v]){
            dfs(adj,visited,tn,low,timer,ans,v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>tn[u]){
                ans.push_back({u,v});
            }
        }
        else{
            low[u]=min(low[u],low[v]);

        }
    }

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        vector<int> tn(n);
        vector<int> low(n);
        vector<vector<int>> adj(n);
        for(vector<int> &edge:connections){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<vector<int>> ans;
        int timer=0;
        for(int i=0;i<n;i++){
            if(!visited[i]) dfs(adj,visited,tn,low,timer,ans,i,-1);
        }
        return ans;
        
    }
};