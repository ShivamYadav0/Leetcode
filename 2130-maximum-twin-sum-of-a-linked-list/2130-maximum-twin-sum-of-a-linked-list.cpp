#define lt ListNode
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    }
    lt* rev(lt* head){
        lt *prev = NULL, *curr = head, *tmp = NULL;
        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        lt *tmp = NULL, *slow = head, *fast = head;
        while(fast and fast->next) tmp = slow, slow = slow->next, fast = fast->next->next;
        tmp->next = NULL;
        lt *t1 = head, *t2 = rev(slow);
        int maxi = INT_MIN;
        while(t1 and t2){
            maxi = max(maxi, t1->val + t2->val);
            t1 = t1->next;
            t2 = t2->next;
        }
        return maxi;
    }
};