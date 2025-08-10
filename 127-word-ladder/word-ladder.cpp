class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;
        unordered_set<string> s;
        for(auto &st:wordList){
            s.insert(st);
        }
         if (s.find(endWord) == s.end()) return 0; // endWord not in list
        int count=0;
        bool find=false;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        count++;
        if(s.find(beginWord)!=s.end()) {
            s.erase(beginWord);
        }
        while(!q.empty()){
            
            auto it =q.front();
            q.pop();
            string temp=it.first;
            if(temp==endWord){
                count=it.second;
                find=true;
                break;
            }
            for(int i=0;i<temp.size();i++){
                for(char ch='a';ch<='z';ch++){
                    string temp2=temp;
                    temp2[i]=ch;
                    if(s.find(temp2)!=s.end()){
                        q.push({temp2,it.second+1});
                        s.erase(temp2);
                    }
                }
            }
            
        }
        return (find)?count:0;
        

    
        
    }
};