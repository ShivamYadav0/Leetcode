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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool check(ListNode*head,TreeNode*root){ // function for checking the existence of the list
            if(!head) return true; // if we reach the end of the list that means the list is present and return true
            else if(!root) return false;// if the tree finishes before the list then it is not present and hence return false
            else {
                 if(root->val == head->val){ // if the current node val matches the list head then go and check downwards
                    return check(head->next,root->left) || check(head->next,root->right);
                 }
                 else return false; // if not then return false
            }
        
    }

    bool isSubPath(ListNode* head, TreeNode* root) { // we are using this function as preorder traversal
        if(!root) return false;
        if(root->val == head->val){ // if the current node val is equals to the list head val then only check the complete list
            if( check(head,root)) return true;
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right); // else check for left and right subtrees as we usually do in preorder traversal
    }
};