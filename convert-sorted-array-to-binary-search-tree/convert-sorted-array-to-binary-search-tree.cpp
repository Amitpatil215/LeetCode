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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums,int s, int e){
        if(s>e) return NULL;
        int mid=(e+s)/2;
        int rootData=nums[mid];
         
        TreeNode* node=new TreeNode(rootData);
        node->left=sortedArrayToBSTHelper(nums,s,mid-1);
        node->right=sortedArrayToBSTHelper(nums,mid+1,e);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums,0,nums.size()-1);
    }
};