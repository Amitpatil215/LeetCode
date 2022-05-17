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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<int> anss;
        if(root==NULL){
            return anss;
        }
        
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode * front=q.front();
            q.pop();
            
            if(front==NULL){
                ans.push_back(101);
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                ans.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }

        for(int i=0;i<ans.size()-1;i++){
            if(ans[i+1]==101){
                anss.push_back(ans[i]);
            }
        }
     return anss;   
    }
};