class Solution {
public:
int find(int i,vector<int>& parent){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i],parent);
}
void dsunion(int x, int y,vector<int>& parent,vector<int>& rank ){
    int xp=parent[x];
    int yp=parent[y];
    if(xp==yp) return;
    if(rank[xp]>rank[yp]){
        parent[yp]=xp;
    }
    else if(rank[xp]<rank[yp]){
        parent[xp]=yp;

    }
    else{
        parent[yp]=xp;
        rank[xp]++;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int cp=n;
        int cn=0;
        for(vector<int> &edge:connections){
            int u=edge[0];
            int v=edge[1];
            if(find(u,parent)==find(v,parent)) cn++;
            else{
                dsunion(u,v,parent,rank);
                cp--;
            }
        }
        if(cp==1) return 0;
        if(cp-cn>1) return -1;
        return cp-1;
        
    }
};