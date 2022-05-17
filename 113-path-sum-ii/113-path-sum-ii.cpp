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
    
    vector<vector<int>> helper(TreeNode *root, int sum, int targetSum,vector<vector<int>> &ans, vector<int> &subAns){
      
        if(root==NULL){
            return ans;
        }
        sum+=root->val;
        subAns.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum==targetSum){
            ans.push_back(subAns);
        }else{
            helper(root->left,sum,targetSum,ans,subAns);
            helper(root->right,sum,targetSum,ans,subAns);
        }
        subAns.pop_back();
        return ans;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int> subAns;
        return helper(root,0,targetSum,ans,subAns);    
    }
};