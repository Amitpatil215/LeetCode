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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrder;
        queue<TreeNode*> q;
        
        if(root==NULL) return levelOrder;
        q.push(root);
        q.push(NULL);
        
        vector<int> v;
        while(!q.empty()){
            TreeNode* frontElement=q.front();
            q.pop();
            
            if(frontElement==NULL){
                 levelOrder.push_back(v);
                 v.clear();
                
                if(!q.empty()){
                    q.push(NULL);    
                }
                
             }else{
                 v.push_back(frontElement->val);
                
                 if(frontElement->left!=NULL){
                    q.push(frontElement->left);        
                 } 
                 if(frontElement->right!=NULL){
                     q.push(frontElement->right);
                 }
            }
            
        }
        return levelOrder;
    }
};