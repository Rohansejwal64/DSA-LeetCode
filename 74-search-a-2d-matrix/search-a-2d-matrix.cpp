class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int e=(matrix.size()*matrix[0].size())-1;
        int mid=s+((e-s)/2);
        while(s<=e){
            int element=matrix[mid/(matrix[0].size())][mid%matrix[0].size()];
            if(element==target){
                return 1;
            }
            if(element<target){
                s=mid+1;
            }
            if(element>target){
                e=mid-1;
            }
            mid=s+((e-s)/2);

        }
        return 0;
    }
};