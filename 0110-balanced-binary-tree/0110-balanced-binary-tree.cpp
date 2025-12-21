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
    bool isBalanced(TreeNode* root) {
        pair<int, bool> res = dfs(root);
        return(res.second);
    }

    pair<int, bool> dfs(TreeNode* root){
        if(!root){
            return(make_pair(0, true));
        }

        auto r = dfs(root->right);
        auto l = dfs(root->left);
        int h = max(r.first, l.first) +1;
        bool bal = (r.second && l.second && (abs(r.first - l.first)<=1));
        return(make_pair(h, bal));
    }
};