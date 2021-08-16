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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow =head;
        ListNode *fast =head;
        
        while(n>0){
            fast=fast->next;
            n--;
        }
        
        // special case if we need to delete first node
        if(fast==NULL){
            return slow->next;
        }
        
        while(fast && fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode *prev=slow;
        ListNode *temp=prev->next;
        
        prev->next=temp->next; 
        
        delete temp;
        
        return head;
    }
};