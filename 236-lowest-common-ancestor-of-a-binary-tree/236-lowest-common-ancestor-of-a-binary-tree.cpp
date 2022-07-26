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
        
        int pVal = p->val;
        int qVal = q->val;
        int rootVal = root->val;
        
        if(rootVal == pVal || rootVal ==qVal){
            return root;
        }
        
        auto leftCommonAncester = lowestCommonAncestor(root->left,p,q);
        auto rightCommonAncester = lowestCommonAncestor(root->right,p,q);
        
        if(leftCommonAncester==NULL && rightCommonAncester==NULL){
            return NULL;
        }else if(leftCommonAncester!=NULL && rightCommonAncester==NULL){
            return leftCommonAncester;
        }else if(leftCommonAncester==NULL && rightCommonAncester!=NULL){
            return rightCommonAncester;
        }else{
            // p and q must be in the left and right of the root node
            return root;
        }
    }
};