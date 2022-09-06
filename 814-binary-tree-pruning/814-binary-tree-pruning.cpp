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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        
        TreeNode* left=NULL;
        TreeNode* right=NULL;
        
        if(root->left){
            left = pruneTree(root->left);
        }
        
        if(root->right){
            right = pruneTree(root->right);
        }
        root->left = left;
        root->right =right;
        
        if(left==NULL && right == NULL){
            if(root->val == 0){
                root = NULL;
            } 
        }
        return root;
    }
};