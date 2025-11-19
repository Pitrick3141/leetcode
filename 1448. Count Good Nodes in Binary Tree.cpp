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
    int getGoodNodes(TreeNode* root, int currentMax) {
        if(!root) return 0;
        if(root -> val >= currentMax) return getGoodNodes(root -> left, root -> val) + getGoodNodes(root -> right, root -> val) + 1;
        return getGoodNodes(root -> left, currentMax) + getGoodNodes(root -> right, currentMax);
    }
    int goodNodes(TreeNode* root) {
        return getGoodNodes(root, -100000);
    }
};