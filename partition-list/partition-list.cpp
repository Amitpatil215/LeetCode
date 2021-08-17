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
        ListNode *LH=NULL, *LT=NULL, *MH=NULL, *MT=NULL; // l->Less M->More T->Tail H->Head
        
        while(head!=NULL){
            if(head->val<x){
                if(LH==NULL){
                    LH=LT=head;
                }else{
                    LT->next =head;
                    LT=LT->next;
                }
            }else{
                
                if(MH==NULL){
                    MH=MT=head;
                }else{
                    MT->next=head;
                    MT=MT->next;
                }
            }
            head=head->next;
        }
        
        // now our LL are ready and their tail must be pointing to NULL
        if(LT!=NULL)
        LT->next=NULL;
        
        if(MT!=NULL)
        MT->next=NULL;
        
        // now we need to merge both less and more linked list
        if(LH==NULL && MH==NULL){
            return NULL;
        }else if(LH!=NULL && MH==NULL){
            return LH;
        }else if(LH==NULL && MH!=NULL){
            return MH;
        }else if(LH!=NULL && MH!=NULL){
            LT->next=MH;
            return LH;
        }

        return head;
    }
};