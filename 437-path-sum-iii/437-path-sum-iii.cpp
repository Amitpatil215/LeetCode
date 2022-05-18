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
    int helper(TreeNode* root, int targetSum,deque<int>path){
        if(root==NULL){
            return 0;
        }
        path.push_back(root->val);
        int pathCount=0;
        long long pathsum=0;
        for(int i=path.size()-1;i>=0;i--){
            pathsum+=path[i];
            if(pathsum==targetSum){
            pathCount++;
            }
        }
        
        pathCount+= helper(root->left,targetSum,path)+helper(root->right,targetSum,path);
        path.pop_back();
        return pathCount;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
       deque<int>path;
       return helper(root,targetSum,path);
    }
};