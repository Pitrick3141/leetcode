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
    int heightSum[10010];
    int maxHeightSum = -2147483648;
    int maxHeight = -1;
    int maxLevel = -1;
    void dfs(TreeNode* root, int height) {
        if(!root) return;
        maxHeight = max(maxHeight, height);
        heightSum[height] += root -> val;
        dfs(root -> left, height + 1);
        dfs(root -> right, height + 1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        for(int i = 1; i <= maxHeight; i++) {
            if(heightSum[i] > maxHeightSum) {
                maxHeightSum = heightSum[i];
                maxLevel = i;
            }
        }
        return maxLevel;
    }
};