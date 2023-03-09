/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)return NULL;
        ListNode * s,*f;
        s=f=head;
        while(1){
            s=s->next;
            f=f->next;
            if(!f)return NULL;
            f=f->next;
            if(!f)return NULL;
            if(s==f)break;
        }
        s=head;
        if(s==f)return s;
        while(1){
            s=s->next;
            f=f->next;
            if(s==f)return s;
        }
        return s;
    }
};