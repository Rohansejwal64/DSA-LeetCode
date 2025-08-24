class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                temp.push_back(nums1[i++]);
            }
            else{
                temp.push_back(nums2[j++]);

            }
        }
        if(i==nums1.size()){
            while(j<nums2.size()){
                temp.push_back(nums2[j++]);
            }
        }
        if(j==nums2.size()){
            while(i<nums1.size()){
                temp.push_back(nums1[i++]);
            }

        }
        int n=temp.size();
        if(n%2==0){
            return double(temp[n/2]+temp[(n/2)-1])/2.0 ;
        }
        else{
            return double(temp[n/2]);
        }
        
    }
};