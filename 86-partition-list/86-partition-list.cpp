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
    ListNode* partition(ListNode* head, int x) {
        ListNode *LH=NULL,*LT=NULL,*MH=NULL,*MT=NULL;
        while(head!=NULL){
            if(head->val<x){
                if(LH==NULL){
                    LH=LT=head;       
                }else{
                    LT->next = head;
                    LT= LT->next;
                }        
            }else{
                if(MH==NULL){
                    MH=MT=head;       
                }else{
                    MT->next = head;
                    MT= MT->next;
                }
            }
            head=head->next;
        }
        
        // now point end of LT & MT to NULL
        if(LT){
            LT->next = NULL;
        }
        if(MT){
            MT->next = NULL;
        }
        
        // connect both the list
        if(LH==NULL && MT==NULL){
            return NULL;
        }else if(LH && MH){
             LT->next=MH;
            return LH;
        }else if(LH){
            return LH;
        }else{
            return MH;
        }
    }
};