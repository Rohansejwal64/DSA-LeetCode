#include <unordered_map>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
         unordered_map<int, int> freq;
         for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
         }
         unordered_set<int> seen;

    // Step 2: Check if frequencies are unique
    for (auto &pair : freq) {
        if (seen.count(pair.second)) {
            return false; // Duplicate frequency found
        }
        seen.insert(pair.second);
    }

    return true; // All frequencies are unique
     
        
    }
};