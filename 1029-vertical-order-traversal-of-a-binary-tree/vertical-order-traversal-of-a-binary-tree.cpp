/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) .first{}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode* ,pair<int,int>> > q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* curr= q.front().first;
            int h=q.front().second.first;
            int l=q.front().second.second;
            nodes[h][l].insert(curr->val);
            q.pop();
            if(curr->left) q.push({curr->left,{h-1,l+1}});
             if(curr->right) q.push({curr->right,{h+1,l+1}});

        }
        vector<vector<int>> ans;
        for(auto &v:nodes){
            vector<int> temp;
            for(auto & w: v.second){
                temp.insert(temp.end(),w.second.begin(),w.second.end());
            }
            ans.push_back(temp);
        }
        return ans;

    }
};