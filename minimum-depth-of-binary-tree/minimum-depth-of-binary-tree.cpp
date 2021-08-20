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
    class element{
        public: 
        TreeNode * node;
        int depth;
        
        element(TreeNode * node ,int depth){
            this->node=node;
            this->depth=depth;
        }
    };
    
    int minDepth(TreeNode* root) {
        queue<element> q;
        element e(root, 1);
        
        if(root==NULL)return 0;
        
        q.push(e);
        
        while(!q.empty()){
            
            element currElement=q.front();
            q.pop();
            
            if(currElement.node->left == NULL && currElement.node->right==NULL){
                return currElement.depth;
            }
            if(currElement.node->left!=NULL){
                element e(currElement.node->left,currElement.depth + 1);
                q.push(e);
            } 
            if(currElement.node->right!=NULL){
                element e(currElement.node->right,currElement.depth + 1);
                q.push(e);
            }
        }
        return 0;
    }
};