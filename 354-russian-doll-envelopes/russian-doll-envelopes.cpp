class Solution {
public:
int lis(vector<int>& arr) {
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i=1;i<=arr.size()-1;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int j=lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
                temp[j]=arr[i];
            }
        }
        return temp.size();
        
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) return a[1] > b[1]; // same width → sort height descending
        return a[0] < b[0]; // otherwise width ascending
    });

        vector<int> arr(env.size(),0);
        for(int i=0;i<env.size();i++){
            arr[i]=env[i][1];
        }
        return lis(arr);

        
    }
};