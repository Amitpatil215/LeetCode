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
    bool dfs(TreeNode *node,int sum,int targetSum){
        if(node==NULL){
            return false;
        }
        sum+=node->val;
        if(!(node->left) && !(node->right)){
            return sum==targetSum;
        }
        bool left=dfs(node->left,sum,targetSum);
        bool right=dfs(node->right,sum,targetSum);
        return left || right;
        
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return dfs(root,sum,targetSum);
    }
};