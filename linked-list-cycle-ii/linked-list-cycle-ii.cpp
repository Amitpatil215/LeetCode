/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast &&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                break; // cycle detected
            }
        }
        
        // cycle does not exist
        if(fast==NULL || fast->next==NULL) 
            return NULL;
        
        // find size of the loop
        slow=slow->next;
        int loopSize=1;
        while(slow!=fast){
            loopSize++;
            slow=slow->next;
        }
        
        // find the starting point of the cycle
        slow=head;
        fast=head;
        while(loopSize--){
            fast=fast->next;
        }
        
        // if we got the stating position 
        if(fast==slow) return slow;
        
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
            if(slow==fast){
                return slow;
            }
           
        }
        
         return NULL;
    }
};