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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        ListNode* ptr = head;

        int left =0;
        int right = n-1;
        int top =0;
        int bottom = m-1;
        
        while(ptr != NULL && top<=bottom && left <= right){

            for(int i=left; i<=right && ptr != NULL ; ++i){
                matrix[top][i] = ptr -> val;
                ptr = ptr -> next;
            }
            ++top;
            for(int i=top ; i<=bottom && ptr != NULL; ++i){
                matrix[i][right] = ptr -> val;
                ptr = ptr -> next;
            }
            --right;


           for(int i= right; i>=left  && ptr != NULL;--i){
            matrix[bottom][i] = ptr -> val;
            ptr = ptr -> next;
           }
           --bottom;
            for(int i=bottom; i>= top &&  ptr != NULL ;--i ){
            matrix[i][left] = ptr -> val;
            ptr = ptr -> next;
            }
            ++left;

            
        }

return matrix;
      
    }
};