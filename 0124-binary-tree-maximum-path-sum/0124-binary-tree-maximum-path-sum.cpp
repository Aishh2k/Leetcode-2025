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
    int maxSum = INT_MIN;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int l = solve(root->left);
        int r = solve(root->right);

        int either = max(l, r) + root->val;
        int none = root->val;
        int found = l+r+ root->val;

        maxSum = max({maxSum, either, none, found});

        return max(either, none);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};