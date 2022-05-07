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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<int> subRes;
        if(root==NULL) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode * front=q.front();
            q.pop();
            if(front==NULL){
                double sum=0;
                for(auto e:subRes){
                    sum+=e;
                }
                double avg=sum/subRes.size();
                res.push_back(avg);
                
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
        return res;
    }
};