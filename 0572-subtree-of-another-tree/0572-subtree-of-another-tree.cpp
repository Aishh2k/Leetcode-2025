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
    bool sameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        return (sameTree(p->left, q->left) && sameTree(p->right, q->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL){
            return false;
        }

        if(subRoot == NULL){
            return true;
        }

        if(sameTree(root, subRoot)){
            return true;
        }else{
            return(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
        }

    }
};