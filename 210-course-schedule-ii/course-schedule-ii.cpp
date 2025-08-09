class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);


        for(vector<int> &vec:prerequisites){
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;

        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int &v:adj[u]){
                if (--indegree[v] == 0) q.push(v);
            }

        }

        return ans.size() == numCourses ? ans : vector<int>{};
        
        
    }
};