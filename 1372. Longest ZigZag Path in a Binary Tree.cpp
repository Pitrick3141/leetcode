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
    int maxLength = 0;
    void explore(TreeNode* root, bool isLeft, int sum) {
        if(!root) return;
        maxLength = max(maxLength, sum);
        explore(root -> right, false, isLeft ? sum + 1 : 1);
        explore(root -> left, true, isLeft ? 1 : sum + 1);
    }
    int longestZigZag(TreeNode* root) {
        explore(root, false, 0);
        return maxLength;
    }
};