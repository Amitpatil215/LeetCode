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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        
        //if start and end exist in opposite tree
        int diameterForBoth=height(root->left)+height(root->right);
        //if start and end exist in left tree only
        int diameterForLeft=diameterOfBinaryTree(root->left);
         //if start and end exist in left right only
        int diameterForRight=diameterOfBinaryTree(root->right);
        
        return max(diameterForBoth,max(diameterForLeft,diameterForRight));
    }
};