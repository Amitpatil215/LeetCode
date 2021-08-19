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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelOrder;
        queue<TreeNode *> q;
        if(root==NULL) return levelOrder;
        q.push(root);
        q.push(NULL);
        
        vector<int> v;
        while(!q.empty()){
         TreeNode * front=q.front();
            q.pop();
            if(front==NULL){
                levelOrder.push_back(v);
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
        reverse(levelOrder.begin(), levelOrder.end());
        return levelOrder;
    }
};