/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> level;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front==NULL){
                ans.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                level.push_back(front->val);
                for(auto node : front->children){
                    q.push(node);
                }
            }
            
        }
        return ans;
    }
};