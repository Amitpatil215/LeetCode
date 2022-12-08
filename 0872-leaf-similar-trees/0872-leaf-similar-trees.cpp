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
    void traversal(TreeNode* root,vector<int>&values){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            values.push_back(root->val);
        }
        traversal(root->left,values);
        traversal(root->right,values);
    } 
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> values1,values2;
        traversal(root1,values1);
        traversal(root2,values2);
        if(values1.size()!=values2.size()){
            return false;
        }
        for(int i=0;i<values1.size();i++){
            if(values1[i]!=values2[i]){
                return false;
            }
        }
        return true;
    }
};