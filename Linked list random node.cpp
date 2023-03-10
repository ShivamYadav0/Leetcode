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
  ListNode *a,*b;
    int n=0;
    Solution(ListNode* head) {
      a=head;
      b=head;
      while(b){
          b=b->next;
         n++;
      }
      b=a;
    }
    
    int getRandom() {
        int r=rand()%(n);
        
        
       b=a;
      while(r>0){
        b=b->next;
          r--;
      }
    
      int v=b->val;
        return v;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
