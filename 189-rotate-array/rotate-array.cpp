class Solution {
public:
void rev(vector<int> &arr,int st,int end){
        while(st<=end){
            swap(arr[st],arr[end]);
            st++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
       rev(nums,0,n-k-1);
       rev(nums,n-k,n-1);
       rev(nums,0,n-1);
        
    }
};