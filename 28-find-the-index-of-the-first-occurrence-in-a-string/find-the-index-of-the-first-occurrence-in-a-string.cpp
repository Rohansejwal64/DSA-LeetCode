class Solution {
public:
    int strStr(string txt, string pat) {
        int siz=pat.size();
       
        for(int i=0;i<txt.size();i++){
            string temp;
            for(int j=i; j<txt.size() && j<i+siz;j++){
                temp.push_back(txt[j]);
            }
            if(temp==pat){
                return i;
                
            }
        }
        return -1;
        
    }
};