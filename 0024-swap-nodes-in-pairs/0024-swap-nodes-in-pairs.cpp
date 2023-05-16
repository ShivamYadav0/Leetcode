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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
       ListNode *a=NULL;
        ListNode * b=head;
        ListNode * c=head->next;
        //if(head->next)
        head=head->next;
       while(c!=NULL){
           //cout<<b->val<<" ";
            b->next=c->next;
            c->next=b;
           if(a!=NULL){
               a->next=c;
           }
            
            a=b;
            b=b->next;
           if(b==NULL)break;
            c=b->next;
           
        }
       return head;
    }
};