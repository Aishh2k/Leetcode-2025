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
    void traversal(vector<int>& trav, TreeNode* root){
        if(root == NULL){
            return;
        }
        traversal(trav, root->left);
        trav.push_back(root->val);
        traversal(trav, root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> trav;

        traversal(trav,root);
        return trav[k-1];
    }
};