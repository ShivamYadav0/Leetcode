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
    void print(ListNode *head){
        ListNode *cur=head;
        while(cur!=NULL){
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    vector<ListNode *> reverse(ListNode * from, ListNode*to){
        if(!from || !to)return {from,from};
        ListNode * cur,*prev,*next;
        prev=from;
        cur=from->next;
        if(!cur){
            return {from,from};
        }
        
        next=cur->next;
        while(cur!=NULL){
            cur->next=prev;
            prev=cur;
            cur=next;
            if(prev==to)break;
            if(next)
            next=next->next;
        }
       // from->next=NULL;
      //  print(to);
        return {to,from};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode *cur=head,*pit=head,*next,*prev=NULL;
        ListNode *newHead=NULL;
        int i=1;
        while(cur!=NULL){
            if(i==k){
                next=cur->next;
              
                reverse(pit,cur);
                if(prev)prev->next=cur;
                prev=pit;
                if(!newHead)newHead=cur;
                cur=next;
                pit->next=cur;
                pit=cur;
              
                i=0;
            }
            else cur=cur->next;
            i++;
        }
       // reverse(head,head->next->next);
       
        return newHead;
    }
};