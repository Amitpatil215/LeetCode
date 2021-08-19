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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        queue<TreeNode *> q;
        bool LTR=true; // left to right
        if(root==NULL) return zigzag;
        
        q.push(root);
        q.push(NULL);
        
        vector<int> v;
        while(!q.empty()){
            TreeNode * front=q.front();
            q.pop();
            if(front==NULL){
                if(LTR){
                 zigzag.push_back(v);
                }else{
                 reverse(v.begin(),v.end());
                 zigzag.push_back(v);   
                }
                LTR=!LTR;
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                
            }else{
                v.push_back(front->val);
               
                    if(front->left!=NULL){
                        q.push(front->left); 
                    }
                    
                    if(front->right!=NULL){
                      
                        q.push(front->right);
                    }         
                
            }
        }
        return zigzag;
    }
};