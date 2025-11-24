/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool foundp = false, foundq = false;
    vector<int> path;
    TreeNode* lowest = nullptr;
    void findP(TreeNode* root, TreeNode* p) {
        if(!root) return;
        if(!foundp) {
            if(root == p) foundp = true;
            else{
                findP(root -> left, p);
                findP(root -> right, p);
            }
            if(foundp) path.push_back(root -> val);
        }
    }
    void findQ(TreeNode* root, TreeNode* q) {
        if(!root) return;
        if(!foundq) {
            if(root == q) foundq = true;
            else {
                findQ(root -> left, q);
                findQ(root -> right, q);
            }
            if(foundq) {
                if(find(path.begin(), path.end(), root -> val) != path.end() && !lowest) lowest = root; 
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findP(root, p);
        findQ(root, q);
        return lowest;
    }
};