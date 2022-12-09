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
    int mad(TreeNode* root,int maxVal, int minVal){
        if(root==NULL){
            return 0;
        }
        int left = mad(root->left, max(maxVal,root->val), min(minVal,root->val));
        int right = mad(root->right, max(maxVal,root->val), min(minVal,root->val));
        return max({left,right,abs(maxVal-root->val),abs(minVal-root->val)});
    }
    int maxAncestorDiff(TreeNode* root) {
        return mad(root,root->val,root->val);
    }
};