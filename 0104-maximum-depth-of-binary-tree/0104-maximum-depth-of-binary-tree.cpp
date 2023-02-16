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
    int maxDepth(TreeNode* root) {
  if(!root) return 0;
  if(!root->left && !root->right) return 1; 
   int lh=INT_MIN,rh=INT_MIN;
if(root->left)             
  lh=maxDepth(root->left); 
if(root->right)
 rh=maxDepth(root->right);

return max(lh,rh)+1;
    

    }
};