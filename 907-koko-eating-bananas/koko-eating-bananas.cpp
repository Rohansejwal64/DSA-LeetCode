class Solution {
public:
int solve(vector<int>& piles, int mid){
    if (mid==0) return INT_MAX;
    int th=0;
    for(int i=0;i<piles.size();i++){
        th+=piles[i]/mid;
        if(piles[i]%mid !=0) th++;
    }
    return th;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(maxi<piles[i]) maxi=piles[i];
        }
        
        int s=0;
        int e=maxi;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int hours=solve(piles,mid);
            if(hours<=h){
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