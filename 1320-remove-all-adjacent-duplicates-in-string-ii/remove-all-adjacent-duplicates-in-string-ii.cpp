class Solution {
public:
bool solve(string temp){
    for(int i=0;i<temp.size()-1;i++){
        if(temp[i]!=temp[i+1]){
            return false;
        }
    }
    return true;

}
    string removeDuplicates(string s, int k) {


        string res;

        for(char &c: s){
            res.push_back(c);
            if(res.size()>=k ){
                if(solve(res.substr( res.size()-k, k))){
                    res.erase(res.size()-k);
                }
            }

        }
        return res;
        
    }
};