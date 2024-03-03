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
  
  ListNode *s,*f; 
  s=f=head;
  int c=0;
  int sz;
  while(f&&(f->next)){
  c++;
  s=s->next;
  f=f->next;
  f=f->next;
  }
  if(!(f)){
  sz=2*c;
  }
  else {
  sz=2*c+1;
  }
 if(sz==n) return head=head->next;
  s=f=head;
  c=0;
  //cout<<sz;
  
  while(c<sz-n-1){
   c++; 
   s=s->next;
  }
 s->next=(s->next->next); 
 return head;
 }
};