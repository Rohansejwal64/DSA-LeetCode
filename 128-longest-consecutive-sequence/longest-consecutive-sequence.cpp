class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int largest=1;
        int cnt=0;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto v:st){
            if(st.find(v-1) !=st.end()){
                continue;
            }
            else{
                cnt=1;
                int x=v;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x=x+1;

                }
            }
            largest=max(largest,cnt);
        }
        return largest;

        
    }
};