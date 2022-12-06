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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * oddHead = head, *copyOddHead;
        copyOddHead=oddHead;
        ListNode* evenHead = head!=NULL ? head->next : NULL, *copyEvenHead;
        copyEvenHead = evenHead; 
        while(oddHead!=NULL && evenHead!=NULL){
            oddHead->next = oddHead->next!=NULL ? oddHead->next->next : NULL;
            evenHead->next = evenHead->next!=NULL ? evenHead->next->next : NULL;
            if(oddHead->next!=NULL)
                oddHead=oddHead->next;
            evenHead=evenHead->next;
        }
        cout<<oddHead<<endl;
        if(oddHead!=NULL){
            
            oddHead->next=copyEvenHead;
        }
        return copyOddHead;
    }
};