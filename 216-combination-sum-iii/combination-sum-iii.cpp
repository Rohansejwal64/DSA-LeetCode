class Solution {
public:
void solve(int k, int n,vector<vector<int>> &ans,vector<int> &temp, int sum, int start ){
    if(sum==n && temp.size()==k){
        ans.push_back(temp);
    }
    for(int i=start;i<=9;i++){
        if(i>n || sum>n || temp.size()>=k ) break;
        temp.push_back(i);
        solve(k,n,ans,temp,sum+i,i+1);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k,n,ans,temp,0,1);
        return ans;
        
    }
};