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
    int height = 0;
    vector<int> view;
    void dfs(TreeNode* root, int currentHeight) {
        if(!root) return;
        if(currentHeight > height) {
            view.push_back(root->val);
            height = currentHeight;
        }
        dfs(root -> right, currentHeight + 1);
        dfs(root -> left, currentHeight + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return view;
    }
};