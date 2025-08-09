class Solution {
public:

bool dfs(vector<vector<int>>& graph,vector<int> &color,int u, int ucolor){
    for(int &v: graph[u]){
        if(color[v]==ucolor) return false;
        if(color[v]==-1){
            color[v]=1-ucolor;
            if(dfs(graph,color,v,color[v])==false) return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i=0; i<V;i++){
            if(color[i]==-1){
                color[i]=1;
                if(dfs(graph,color,i,1)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};