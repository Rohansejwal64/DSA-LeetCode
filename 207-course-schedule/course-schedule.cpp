class Solution {
public:

bool dfs(vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &inrecursion,int u){
    visited[u]=true;
    inrecursion[u]=true;
    for(int &v:adj[u]){
        if(visited[v] && inrecursion[v]) return true;
        if(!visited[v] && dfs(adj, visited, inrecursion, v)){
            return true;
        }
    }
    inrecursion[u]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(vector<int> &vec: prerequisites){
            adj[vec[1]].push_back(vec[0]);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> inrecursion(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(adj,visited,inrecursion,i)){
                return false;
            }
        }
        return true;
        
    }
};