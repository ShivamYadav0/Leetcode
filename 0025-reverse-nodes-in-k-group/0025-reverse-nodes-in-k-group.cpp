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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode *cur=head,*next,*prev=NULL;
       
        int ln=0;
        while(cur!=NULL){
            ln++;
            cur=cur->next;
        }
        ln/=k;
      
        ListNode *dum=new ListNode(-1);
        dum->next=head;
        cur=dum;
        next=dum;
        prev=dum;
        while(ln >0){
            
          cur=prev->next;
          next=cur->next;
          for(int i=1;i<k;i++){
              cur->next=next->next;
              next->next=prev->next;
              prev->next=next;
              next=cur->next;
              
              
          }
            prev=cur;
            ln--;
        }
      
       
        return dum->next;
    }
};