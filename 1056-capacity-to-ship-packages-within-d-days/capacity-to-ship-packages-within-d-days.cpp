class Solution {
public:
int solve(vector<int>& arr, int mid){
    int count=0;
    int capa=mid;
    int days=0;
    int i=0;
    while(i<arr.size()){
        if(arr[i]>mid) return INT_MAX;
        if(arr[i]<=capa){
            count++;
            capa-=arr[i++];
            
        }
        else{
            
            
                days++;
                count=0;
                capa=mid;
            
        }
    }
    return days+1;


}
    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        long long int maxi=0;
        for(int i=0;i<n;i++){
            maxi+=arr[i];

        }
        int s=1;
        long long int e=maxi;
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