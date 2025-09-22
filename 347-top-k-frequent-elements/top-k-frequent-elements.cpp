class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Count frequencies
        for(int x : nums){
            freq[x]++;
        }

        // Step 2: Bucket sort by frequency
        vector<vector<int>> bucket(nums.size()+1);

        for(auto &temp : freq){
            int ele = temp.first;
            int f   = temp.second;
            bucket[f].push_back(ele);
        }

        // Step 3: Collect top k from highest frequency bucket
        vector<int> ans;
        for(int i = nums.size(); i >= 0 && k > 0; i--){
            for(int ele : bucket[i]){
                ans.push_back(ele);
                k--;
                if(k == 0) break;
            }
        }

        return ans;
    }
};
