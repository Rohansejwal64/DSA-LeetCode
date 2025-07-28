class Solution {
public:
bool issafe(int row, int col, vector<string> &temp){
    int r=row,c=col;
    while(r>=0 && c>=0){
        if(temp[r][c]=='Q') return false;
        r--,c--;

    }
     r=row,c=col;
    while(r<temp.size() && c>=0){
        if(temp[r][c]=='Q') return false;
        r++,c--;

    }

    return true;
    
}
void solve(int &n,vector<vector<string>> &ans,vector<string> &temp,vector<bool> &rowvis,int c){
    
    if(c==n) {
        ans.push_back(temp);
        return;
    }
    for(int r=0;r<n;r++){
        if(!rowvis[r] && issafe(r,c,temp)){
            temp[r][c]='Q';
            rowvis[r]=true;
            solve(n,ans,temp,rowvis,c+1);
            temp[r][c]='.';
            rowvis[r]=false;

        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            temp[i]=s;
        }

        vector<bool> rowvis(n,false);
        solve(n,ans,temp,rowvis,0);
        return ans;

        
    }
};