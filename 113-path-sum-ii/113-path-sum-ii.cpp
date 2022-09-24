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
    void helper(TreeNode* root, int targetSum, int currSum, vector<int>&currAns, vector<vector<int>>&ans){
        if(root==NULL){
            return ;
        }
        currSum +=root->val;
        currAns.push_back(root->val);
        
        if(currSum == targetSum  && root->right==NULL && root->left==NULL){
            ans.push_back(currAns);
        }
        helper(root->right, targetSum, currSum, currAns, ans);
        helper(root->left, targetSum, currSum, currAns, ans);
        currSum -=root->val;
        currAns.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int>currAns;
        helper(root,targetSum,0,currAns, ans );
        return ans;
    }
};