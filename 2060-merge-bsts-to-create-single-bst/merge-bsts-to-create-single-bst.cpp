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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> roots;  // root value -> root node
        unordered_set<int> children;          // all child values

        // Step 1: Build map of roots and set of child values
        for (auto t : trees) {
            roots[t->val] = t;
            if (t->left) children.insert(t->left->val);
            if (t->right) children.insert(t->right->val);
        }

        // Step 2: Find the main root (it should not appear as any child)
        TreeNode* mainRoot = nullptr;
        for (auto t : trees) {
            if (!children.count(t->val)) {
                if (mainRoot) return nullptr; // More than one root candidate
                mainRoot = t;
            }
        }
        if (!mainRoot) return nullptr; // No unique root found

        // Step 3: Merge all possible trees starting from mainRoot
        if (!dfsMerge(mainRoot, INT_MIN, INT_MAX, roots)) return nullptr;

        // Step 4: After merging, only one root should remain
        if (roots.size() > 1) return nullptr;

        return mainRoot;
    }

private:
    bool dfsMerge(TreeNode* node, int low, int high, unordered_map<int, TreeNode*>& roots) {
        if (!node) return true;
        
        // Check BST property
        if (node->val <= low || node->val >= high) return false;

        // If node exists in roots (and it's not the current root), attach its children
        auto it = roots.find(node->val);
        if (it != roots.end() && it->second != node) {
            node->left = it->second->left;
            node->right = it->second->right;
            roots.erase(it);
        }

        // Recurse left and right with updated bounds
        return dfsMerge(node->left, low, node->val, roots) && dfsMerge(node->right, node->val, high, roots);
    }
};
