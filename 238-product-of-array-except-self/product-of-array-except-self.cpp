class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int> p(n);
        vector<int> s(n);
        p[0]=nums[0];
        s[n-1]=nums[n-1];
        for(int i=1;i<=n-1;i++){
            int pi=i;
            int si=n-1-i;
            p[pi]=p[pi-1]*nums[pi];
            s[si]=s[si+1]*nums[si];
        }
        vector<int> ans(n);
        for(int i=1;i<n-1;i++){
            ans[i]=p[i-1]*s[i+1];
        }
        ans[0]=s[1];
        ans[n-1]=p[n-2];
        return ans;

        
    }
};