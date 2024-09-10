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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *cur=head;
        
        while(cur!=NULL){
            ListNode *nxt=cur->next;
            if(nxt!=NULL){
                int tp=__gcd(nxt->val,cur->val);
                ListNode * add= new ListNode(tp);
                add->next=nxt;
                cur->next=add;
                cur=add;
            }
            cur=cur->next;
        }
        return head;
    }
};