/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL) return NULL;
        
        int rootVal=root->val;
        int pVal=p->val;
        int qVal=q->val;
        
        if(rootVal==pVal || rootVal==qVal){
            return root;
        }
        
        TreeNode * leftLowestCommonAncestor=lowestCommonAncestor(root->left,p,q);
        TreeNode * rightLowestCommonAncestor=lowestCommonAncestor(root->right,p,q);
        
        if(leftLowestCommonAncestor==NULL && rightLowestCommonAncestor==NULL){
            return NULL;
        }else if(leftLowestCommonAncestor!=NULL && rightLowestCommonAncestor==NULL){
            return leftLowestCommonAncestor;
        }else if( leftLowestCommonAncestor==NULL && rightLowestCommonAncestor!=NULL){
            return rightLowestCommonAncestor;
        }else{
            // p might be present in left or right
            // q might be present in right or left
            // so this contradicts
            return root;   
        }
        
    }
};