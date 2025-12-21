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
    int maxD = 0;

public:
    int height(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int r = height(root->right);
        int l = height(root->left);
        return (max(r,l)+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int r = height(root->right);
        int l = height(root->left);
        maxD = max(maxD, r+l);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxD;
    }
};