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
    ListNode* doubleIt(ListNode* head) {
        vector<int>v;
        ListNode * c=head;
        while(c){
            v.push_back(c->val);
            c=c->next;
            
          }
      reverse(v.begin(),v.end());
        int cp=0;
       for(auto &x:v){
           int r=(x*2+cp)%10;
           cp=(x*2+cp)/10;
           x=r;
        }
        if(cp>0)
            v.push_back(cp);
        reverse(v.begin(),v.end());
        c=head;
        int i=0;
        ListNode *p=head;
        while(c){
            c->val=v[i++];
            p=c;
            c=c->next;
            
            }
        while(i<v.size()){
            p->next=new ListNode(v[i++]);
            p=p->next;
          }
        return head;
    }
};