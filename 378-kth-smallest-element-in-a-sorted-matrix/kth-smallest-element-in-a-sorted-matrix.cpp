class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>> pq;
        int r=matrix.size();
        int c=r;
       
        for(int i=0;i<matrix.size();i++){
            pq.push({matrix[i][0],{i,0}});
        }
        int cnt=0;
        int ans=0;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            cnt++;
            int num=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            if(cnt==k){
                ans=num;
                break;
            }
            if(col+1<c){
                pq.push({matrix[row][col+1],{row,col+1}});
            }


        }
        return ans;


        
    }
};