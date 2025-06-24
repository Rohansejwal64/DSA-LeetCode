class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector <int> ans;
        set<int> st;
        int j=0;
        int i=0;
        while(j<nums.size()){
            if(nums[j]==key){
                i=max(i,j-k);
                while(i>=0 && i<nums.size() && i<=k+j){
                    st.insert(i);
                    i++;
                }
                
            }
            
                j++;
            
        }
        for(auto &v:st){
            ans.push_back(v);
        }
        return ans;

        
    }
};