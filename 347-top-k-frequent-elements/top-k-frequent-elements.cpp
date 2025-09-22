class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Step 1: Count frequencies
        for(int x : nums){
            freq[x]++;
        }

        // Step 2: Store in vector of pairs (element, frequency)
        vector<pair<int,int>> temp;
        for(auto &p : freq){
            temp.push_back({p.first, p.second});
        }

        // Step 3: Sort by frequency in descending order
        sort(temp.begin(), temp.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second > b.second; 
        });

        // Step 4: Take top k elements
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }

        return ans;
        
    }
};