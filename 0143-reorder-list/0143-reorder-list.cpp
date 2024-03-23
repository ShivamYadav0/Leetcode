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
    void reorderList(ListNode* head) {
        
        
        vector<ListNode*>v;
        ListNode *cur=head;
        int c=0;
        while(cur!=NULL){
            c++;
            v.push_back(cur);
            cur=cur->next; 
        }
        cur=head;
        int j=0;
        while(j<c/2){
            ListNode *d=cur->next;
            cur->next=v[v.size()-j-1];
            v[v.size()-j-1]->next=d;
            cur=d;
            j++;
        }
        cur->next=NULL;
        
    }
};