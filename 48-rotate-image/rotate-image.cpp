class Solution {
public:
void solve(vector<vector<int>>& matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}
void solve2(vector<vector<int>>& matrix, int &row){
    int i=0;
    int j=matrix.size()-1;
    while(i<=j){
        swap(matrix[row][i],matrix[row][j]);
        i++,j--;
    }

}
    void rotate(vector<vector<int>>& matrix) {
        solve(matrix);
        for(int i=0;i<matrix.size();i++){
            solve2(matrix,i);
        }
        
    }
};