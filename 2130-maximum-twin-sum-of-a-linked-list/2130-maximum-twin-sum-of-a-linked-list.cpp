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
    
    int ans(ListNode *hd){
        int l=0;
        ListNode * head=hd;
        while(head!=NULL){
            l++;
            head=head->next;
        }
        head=hd;
        l/=2;
        
        ListNode *p,*c,*n;
        p=hd;
        c=hd->next;
        n=c->next;
        p->next=NULL;
        while(c&&l>1){
            c->next=p;
            p=c;
            c=n;
            n=n->next;
            l--;
        }
        int mx=0;
        while(p!=NULL){
            mx=max(p->val+c->val,mx);
            p=p->next;
            c=c->next;
        }
        return mx;
    }
    int pairSum(ListNode* head) {
        return ans(head);
        
    }
};