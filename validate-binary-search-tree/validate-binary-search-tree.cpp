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
    bool helper(TreeNode *root, long long min=-10000000000, long long max=10000000000){
        if(root==NULL) return true;
        
        bool leftSubTreeIsBST= helper(root->left,min,root->val);
        bool rightSubTreeIsBST=helper(root->right,root->val,max);
        
        if(leftSubTreeIsBST && rightSubTreeIsBST && root->val > min && root->val < max){
            return true;
        }else{
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return helper(root);
    }
};