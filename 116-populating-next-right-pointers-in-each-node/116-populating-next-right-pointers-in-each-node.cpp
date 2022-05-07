/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node *> q;
        vector<Node *> level; 
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node * front=q.front();
            q.pop();
            if(front==NULL){
                for(int i=0;i<level.size()-1;i++){
                    level[i]->next=level[i+1];
                }
                level[level.size()-1]->next=NULL;
                level.clear();
                
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                level.push_back(front);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return root;
    }
};