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
struct node_cmp
{
   bool operator()( const ListNode* a, const ListNode* b ) const 
   {
    return a->val > b->val;
   }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *l=new ListNode();
        ListNode *c=l;
        bool f=1;
        priority_queue<ListNode*,vector<ListNode *>, node_cmp>pq;
        for(auto x:lists)if(x!=NULL)pq.push(x);
        while(!pq.empty()){
            ListNode *p=pq.top();
            pq.pop();
           // cout<<p->val<<endl;
            l->next=new ListNode(p->val);
            l=l->next;
            p=p->next;
            if(p)pq.push(p);
         }
          
            
        
        
        return c->next;
    }
};