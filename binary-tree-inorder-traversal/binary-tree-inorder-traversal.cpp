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
    
    void  inorderTraversalHelper(TreeNode *root, vector<int> &inOrder){
        if(root==NULL) return ;
        inorderTraversalHelper(root->left, inOrder);
        inOrder.push_back(root->val);
        inorderTraversalHelper(root->right, inOrder);
    }
        
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int> inOrder;
        inorderTraversalHelper(root,inOrder);
        return inOrder;
        
    }
};