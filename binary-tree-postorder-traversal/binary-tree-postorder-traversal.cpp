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
    void postorderTraversalHelper(TreeNode *root, vector<int> &postOrder){
        if(root==NULL) return ;
        postorderTraversalHelper(root->left,postOrder);
        postorderTraversalHelper(root->right,postOrder);
        postOrder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        postorderTraversalHelper(root,postOrder);
        return postOrder;
    }
};