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
    void helper(TreeNode *root,int &sum,vector<int>path){
        if(root==NULL){
            return ;
        }
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            long long tens=1;
            for(int i=path.size()-1;i>=0;i--){
                sum+=path[i]*tens;
                tens=tens*10;
            }
        }else{
            helper(root->left,sum,path);
            helper(root->right,sum,path);
        }
        
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        vector<int> path;
        helper(root,sum,path);
        return sum;
    }
};