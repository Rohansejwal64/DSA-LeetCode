class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        queue<int> q;
        vector<vector<int>> radj(graph.size());
        vector<int> od(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0) {
                q.push(i);
            }
            else{
                for(int &v:graph[i]){
                    radj[v].push_back(i);
                    od[i]++;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int &v:radj[temp]){
                od[v]--;
                if(od[v]==0) q.push(v);

            }

        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};