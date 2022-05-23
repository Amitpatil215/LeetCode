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
    TreeNode* removeLeaf(TreeNode* root, int target){
        if(root==NULL){
               return NULL;
           } 
        root->left=removeLeaf(root->left,target);
        root->right=removeLeaf(root->right,target);
        if(root->left==NULL && root->right==NULL && root->val==target){
            cout<<"deleting node "<<root->val<<endl;
            // delete root;
            return NULL;
        }
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        auto val=removeLeaf(root,target);
        cout<<"returned val "<<val<<endl;
        return val;
    }
};