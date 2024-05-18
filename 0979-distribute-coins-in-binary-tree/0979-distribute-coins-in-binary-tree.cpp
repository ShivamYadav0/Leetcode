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
    int ans=0;
    void rec(TreeNode *rt,TreeNode *pr){
        if(!rt)return ;
      
         rec(rt->left,rt);
         rec(rt->right,rt);
        
         pr->val+=(rt->val-1);
         ans+=abs(rt->val-1);
        
    }
    int distributeCoins(TreeNode* root) {
       
        rec(root,root);
        return ans;
    }
};