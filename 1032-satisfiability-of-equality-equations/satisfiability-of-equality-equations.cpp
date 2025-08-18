class Solution {
public:
int find(int i,vector<int>& parent){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i],parent);
}
void dsunion(int x, int y,vector<int>& parent,vector<int>& rank ){
    int xp=parent[x];
    int yp=parent[y];
    if(xp==yp) return;
    if(rank[xp]>rank[yp]){
        parent[yp]=xp;
    }
    else if(rank[xp]<rank[yp]){
        parent[xp]=yp;

    }
    else{
        parent[yp]=xp;
        rank[xp]++;
    }
}

    bool equationsPossible(vector<string>& equations) {
        
        vector<int> parent(26);
        vector<int> rank(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string &temp: equations){
            if(temp[1]=='='){
                dsunion(temp[0]-'a',temp[3]-'a',parent,rank);
            }
        }
        for(string &temp: equations){
            if(temp[1]=='!'){
                if(find(temp[0]-'a',parent)==find(temp[3]-'a',parent)) return false;
            }
        }
        return true;
        
    }
};