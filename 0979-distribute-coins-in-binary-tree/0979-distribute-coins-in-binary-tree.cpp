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
    void rec(TreeNode *rt,TreeNode *pr,unordered_map<TreeNode*,int>&mp){
        if(!rt)return ;
      
       
        
         rec(rt->left,rt,mp);
         rec(rt->right,rt,mp);
        
         
                pr->val+=(rt->val-1);
                ans+=abs(rt->val-1);
        
          
       
        return ;
        
    }
    int distributeCoins(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        mp[NULL]++;
        rec(root,root,mp);
        return ans;
    }
};