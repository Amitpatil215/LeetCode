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
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> subRes;
        while(!q.empty()){
            TreeNode *front=q.front();
            q.pop();
            if(front==NULL){
                result.push_back(subRes);
                subRes.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
             subRes.push_back(front->val);
            
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }

        }
        reverse(result.begin(),result.end());
        return result;
    }
};