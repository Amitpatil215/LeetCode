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
    TreeNode * buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int poS, int poE){
        if(inS>inE){
            return NULL;
        }
        
        int rootData=postorder[poE];
        int rootIndex=0;
         
        for(int i= inS;i<=inE;i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }
        
        
        int LinS=inS;
        int LinE=rootIndex-1;
        int LPoS=poS;
        int LPoE=LPoS+LinE-LinS;
            
        int RinS=rootIndex+1;
        int RinE=inE;
        int RPoS=LPoE+1;
        int RPoE=poE-1;
        
        TreeNode* node=new TreeNode(rootData);
        node->left=buildTreeHelper(inorder, postorder, LinS,LinE,LPoS,LPoE);
        node->right=buildTreeHelper(inorder, postorder, RinS,RinE,RPoS,RPoE);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          int n=inorder.size();
        return buildTreeHelper(inorder, postorder, 0,n-1,0,n-1);
    }
};