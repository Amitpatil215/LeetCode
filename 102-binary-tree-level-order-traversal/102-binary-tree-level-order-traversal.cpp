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
        
        vector<vector<int>> bfs;
        if(root==NULL){
            return bfs;
        }
        queue<TreeNode *> q;
        vector<int> cuurLevl;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *node= q.front();
            q.pop();
           
            if(node==NULL){
                bfs.push_back(cuurLevl);
                cuurLevl.clear();
                if (!q.empty())
                {
                q.push(NULL);
                }
               
            }
            else{
            cuurLevl.push_back(node->val);
            if(node->left!=NULL){
                q.push(node->left);
            }
             if(node->right!=NULL){
                q.push(node->right);
            }}
            
        }
        return bfs;
    }
};