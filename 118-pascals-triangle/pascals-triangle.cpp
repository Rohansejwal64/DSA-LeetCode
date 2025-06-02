class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> ans;
        for(int i=0;i<=n-1;i++){
            int j=i+1;
            vector<int> temp;
            temp.push_back(1);
            j--;
            while(j>=0){
                if(j>1){
                    for(int k=0;k<=i-2;k++){
                        int sum=ans[i-1][k]+ans[i-1][k+1];
                        temp.push_back(sum);
                        j--;
                    }
                }
                if(j==1){
                    temp.push_back(1);
                    j--;
                }
                if(j==0){
                    ans.push_back(temp);
                    j--;
                }
            }
            
        }
        return ans;
        
    }
};