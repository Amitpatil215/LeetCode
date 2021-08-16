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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head=NULL;
        int carry=0;
        
        while(l1!=NULL && l2!=NULL){
            int n1=l1->val;
            int n2=l2->val;
            
            int sum=n1+n2 +carry;
            
            int val=sum%10;
            carry=sum/10 ;
            
            ListNode *newNode= new ListNode(val);
            
            //insert at head
            newNode->next=head;
            head=newNode;
            
            l1=l1->next;
            l2=l2->next;
        }
        // if one of the linked list still exists
        // if l1 exist
        while(l1!=NULL){
            int sum=l1->val +carry;
            
            int val=sum%10;
            carry=sum/10 ;
            
            ListNode *newNode= new ListNode(val);
            
            //insert at head
            newNode->next=head;
            head=newNode;
            l1=l1->next;
        }
        
        // while l2 exist
         while(l2!=NULL){
            int sum=l2->val +carry;
            
            int val=sum%10;
            carry=sum/10 ;
            
            ListNode *newNode= new ListNode(val);
            
            //insert at head
            newNode->next=head;
            head=newNode;
            l2=l2->next;
        }
        
        // now if carry left over then
        if(carry>0){
            ListNode *newNode= new ListNode(carry);
            
            //insert at head
            newNode->next=head;
            head=newNode;
        }
        
        // reverse a linked list
        ListNode *prev=NULL;
        ListNode *curr =head;
        while(curr!=NULL){
            ListNode *n = curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=n;
        }
        
        head=prev;
        
        return  head;
    }
};