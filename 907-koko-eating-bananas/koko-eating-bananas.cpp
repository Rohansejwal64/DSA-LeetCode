class Solution {
public:
long long solve(vector<int>& piles, int mid) {
    long long th = 0;
    for(int i = 0; i < piles.size(); i++) {
        th += (piles[i] + mid - 1) / mid; // ceil division
    }
    return th;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int maxi = *max_element(piles.begin(), piles.end());
    
    int s = 1, e = maxi, ans = maxi;
    while(s <= e) {
        int mid = s + (e - s) / 2;
        long long hours = solve(piles, mid); // FIXED
        
        if(hours <= h) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}
};