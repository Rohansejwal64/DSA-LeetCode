class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Count frequencies
        for(int x : nums){
            freq[x]++;
        }

       vector<vector<int>> bucket(nums.size()+1);

       for( auto temp : freq){
        int ele= temp.first;
        int f=temp.second;
        bucket[f].push_back(ele);
       }
       vector<int> ans;

       for(int i=nums.size();i>=0;i--){
        if(bucket[i].size()==0) continue;
        while(bucket[i].size()>0 && k>0){
            ans.push_back(bucket[i].back());
            bucket[i].pop_back();
            k--;
        }
       }
       return ans;


        
    }
};