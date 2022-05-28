/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        ListNode* root=NULL;
        auto copyRoot=root;
        int k=lists.size();

        // initially fill the queue
        for(int i=0;i<k;i++){
            if(lists[i]!=NULL){
                int e=lists[i]->val;
                lists[i]=lists[i]->next;
                pq.push({e,i});
                cout<<e<<" "<<i<<endl;
            }
        }
        
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            if(root==NULL){
                root=new ListNode(front.first);
                copyRoot=root;
            }else{
                ListNode * node=new ListNode(front.first);
                root->next=node;
                root=root->next;
            }
            
            if(lists[front.second]!=NULL){
                int e=lists[front.second]->val;
                lists[front.second]=lists[front.second]->next;
                pq.push({e,front.second});
            }
        }
        
        return copyRoot;
    }
};