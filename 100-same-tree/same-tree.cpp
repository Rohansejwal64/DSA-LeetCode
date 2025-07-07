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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q) return false;
        if(p && q==NULL) return false;
        if(p==NULL && q==NULL) return true;
        bool cl=isSameTree(p->left,q->left);
        if(cl==false) return false;
        bool cr=isSameTree(p->right,q->right);
        if(cr==false) return false;
        if(p->val !=q->val) return false;
        return true;

        
    }
};