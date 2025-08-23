class Solution {
public:
bool solve(int mid ,vector<int>& arr, int n, int m){
    int st=1;
    int c=0;
    for(int i=0;i<n;i++){
        if(arr[i]+c<=mid){
            c+=arr[i];
        }
        else{
            st++;
            c=arr[i];
        }
    }
    if(st>m) return false;
    return true;
}
    int splitArray(vector<int>& arr, int m) {
        int n=arr.size();
    int s = *max_element(arr.begin(), arr.end());
    int e = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(solve(mid,arr,n,m)){
            ans=mid;
            e=mid-1;

        }
        else{
            s=mid+1;
        }
    }
    return ans;

        
    }
};