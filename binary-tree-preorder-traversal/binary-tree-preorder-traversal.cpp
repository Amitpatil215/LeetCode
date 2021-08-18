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
    void preorderTraversalHelper(TreeNode * root, vector<int> &preOrder){
        if(root==NULL) return ;
        preOrder.push_back(root->val);
        preorderTraversalHelper(root->left,preOrder);
        preorderTraversalHelper(root->right,preOrder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        preorderTraversalHelper(root,preOrder);
        return preOrder;
    }
};