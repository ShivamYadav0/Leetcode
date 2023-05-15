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
    int getLength(ListNode *head){
        ListNode *cur=head;
        int c=1;
        while(cur!=NULL){
            cur=cur->next;
            c++;
        }
        return c;
    }
    ListNode * getKthNode(ListNode *head,int k){
        ListNode *cur=head;
        int c=1;
        while(cur!=NULL&&c!=k){
            cur=cur->next;
            c++;
        }
        return cur;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=getLength(head);
        
        ListNode * a=getKthNode(head,k);
        ListNode * b=getKthNode(head,n-k);
     
        swap(a->val,b->val);
        return head;
    }
};