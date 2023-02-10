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
    void rec(TreeNode*rt,int mx){
        if(!rt)return;
        if(rt->val>=mx)ans++;
        rec(rt->left,max(mx,rt->val));
        rec(rt->right,max(mx,rt->val));
        
    }
    int goodNodes(TreeNode* root) {
        
        rec(root,-1e5);
        return ans;
    }
};