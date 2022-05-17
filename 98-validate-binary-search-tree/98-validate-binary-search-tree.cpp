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
    bool helper(TreeNode* root,long long int min=-10000000000,long long int max=10000000000){
        if(root==NULL){
            return true;
        }
        bool isLeftValid=helper(root->left,min,root->val);
        bool isRightValid=helper(root->right,root->val,max);
        if(isLeftValid && isRightValid && root->val > min && root->val < max){
            return true;
        }else{
            return false;
        }
        
    }

    bool isValidBST(TreeNode* root) {
      return helper(root);
    }
};