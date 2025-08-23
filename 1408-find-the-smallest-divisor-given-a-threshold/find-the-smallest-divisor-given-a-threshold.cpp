class Solution {
public:
int solve(vector<int>& nums, int mid){
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans+=nums[i]/mid;
        if(nums[i]%mid!=0){
            ans++;
        }

    }
    return ans;

}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi= *max_element(nums.begin(),nums.end());
        int s=1;
        int e=maxi;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int value=solve(nums,mid);
            if(value<=threshold){
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