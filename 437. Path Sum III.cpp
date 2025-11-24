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
    map<long long, int> visited;
    int ans = 0;
    void dfs(TreeNode* root, int targetSum, long long current) {
        if(!root) return;
        current += root -> val;
        if(visited.find(current - targetSum) != visited.end()) ans += visited[current - targetSum];
        if(visited.find(current)!= visited.end()) visited[current] += 1;
        else visited[current] = 1;
        dfs(root -> left, targetSum, current);
        dfs(root -> right, targetSum, current);
        visited[current] -= 1;
    }
    int pathSum(TreeNode* root, int targetSum) {
        visited[0] = 1;
        dfs(root, targetSum, 0);
        return ans;
    }
};