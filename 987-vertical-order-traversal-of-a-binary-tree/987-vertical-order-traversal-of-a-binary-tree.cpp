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
    void vt(TreeNode * root, int level, int col, map<int,map<int,multiset<int>>>&tr){
        if(root==NULL) return;
        tr[col][level].insert(root->val);
        vt(root->left,level+1,col-1,tr);
        vt(root->right,level+1,col+1,tr);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
   
        map<int,map<int,multiset<int>>>tr;
        vt(root,0,0,tr);
        vector<vector<int>>ans;
        
        for(auto col : tr){
            vector<int> ansCol;
            for(auto level: col.second){
                for(auto node :level.second){
                    ansCol.push_back(node);
                }
            }
            ans.push_back(ansCol);
        }
        return ans;
    }
};