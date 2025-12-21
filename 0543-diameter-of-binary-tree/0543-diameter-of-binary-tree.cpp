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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> res = dfs(root); // {dia, height};
        return res.first;
    }

    pair<int, int> dfs(TreeNode* root){
        if(!root){
            return {0,0};
        }

        auto r = dfs(root->right);
        auto l = dfs(root->left);
        int h = 1+ max(r.second, l.second);
        int d = max({r.second+l.second,l.first, r.first });
        return(make_pair(d,h));
    }
};