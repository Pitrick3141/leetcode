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
    string getLeaves(TreeNode* root) {
        if(!root -> left && !root -> right) return to_string(root -> val);
        if(!root -> left && root -> right) return getLeaves(root -> right);
        if(root -> left && !root -> right) return getLeaves(root -> left);
        return getLeaves(root -> left) + "|" + getLeaves(root -> right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return getLeaves(root1) == getLeaves(root2);
    }
};