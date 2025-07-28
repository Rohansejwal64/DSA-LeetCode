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
void solve(int &n,vector<vector<string>> &ans,vector<string> &temp,vector<bool> &rowvis,vector<bool> &diagvis1,vector<bool> &diagvis2,int c){
    
    if(c==n) {
        ans.push_back(temp);
        return;
    }
    for(int r=0;r<n;r++){
        if(!rowvis[r] && !diagvis1[r+c] && !diagvis2[n-1+c-r]){
            temp[r][c]='Q';
            rowvis[r]=true;
            diagvis1[r+c]=true;
            diagvis2[n-1+c-r]=true;
            solve(n,ans,temp,rowvis,diagvis1,diagvis2,c+1);
            temp[r][c]='.';
            rowvis[r]=false;
            diagvis1[r+c]=false;
            diagvis2[n-1+c-r]=false;


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
        vector<bool> diagvis1(2*n-1,false);
        vector<bool> diagvis2(2*n-1,false);

        solve(n,ans,temp,rowvis,diagvis1,diagvis2,0);
        return ans;

        
    }
};