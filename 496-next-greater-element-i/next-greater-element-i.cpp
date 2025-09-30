class Solution {
public:
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size=*max_element(nums2.begin(),nums2.end());
        vector<int> ans(size+1);
        stack<int> st;
        st.push(-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while( st.top() !=-1 && st.top()<=nums2[i]) st.pop();
            ans[nums2[i]]=st.top();
            st.push(nums2[i]);

        }
        vector<int> result(nums1.size());
        for(int i=0;i<nums1.size();i++){
            result[i]=ans[nums1[i]];

        }
        return result;

        
    }

};