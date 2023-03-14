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
 long long s=0; 
 void sum(TreeNode *rt,long long sp){
     if(!(rt->left)&&!(rt->right)) {
        // cout<<sp<<endl;
             
         s+=sp*10+rt->val;
         return;
     }
    if(rt->left)
     sum(rt->left,sp*10+rt->val);
    if(rt->right)
   sum(rt->right,sp*10+rt->val);
     
 }
    int sumNumbers(TreeNode* root) {
     sum(root,0);
      return s;
    }
};