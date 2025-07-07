/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
pair<int,int> solve(TreeNode* root){
    if(root==NULL) {
        pair<int,int> p=make_pair(0,0);
        return p;
}
pair<int,int> ld=solve(root->left);
pair<int,int> rd=solve(root->right);
int op1=ld.first;
int op2=rd.first;
int op3=ld.second+rd.second;
pair<int,int> ans;
ans.first=max(op1,max(op2,op3));
ans.second=max(ld.second,rd.second)+1;
return ans;
}
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
        
    }
};