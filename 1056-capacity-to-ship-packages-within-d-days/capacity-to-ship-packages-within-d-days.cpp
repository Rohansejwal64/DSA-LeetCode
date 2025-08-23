class Solution {
public:
int solve(vector<int>& arr, int mid) {
    int days = 1;   
    int curr = 0;

    for(int i=0; i<arr.size(); i++) {
       // if(arr[i] > mid) return INT_MAX; // can't fit this package
        if(curr + arr[i] > mid) {
            days++;
            curr = arr[i];
        }
        else{
            curr+=arr[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        long long int ts=0;
        int s=INT_MIN;
        for(int i=0;i<n;i++){
            ts+=arr[i];
            s=max(s,arr[i]);


        }
        
        long long int e=ts;
        int ans=-1;
        while(s<=e){
            long long mid=s+(e-s)/2;
            int value=solve(arr,mid);
            if(value<=days){
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