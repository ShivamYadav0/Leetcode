/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int lim=2;
    TreeNode *lca;
    TreeNode* rec(TreeNode *rt,TreeNode *p,TreeNode *q){
        if(!rt){
           return NULL;
        }
        if(rt==p||rt==q) return rt;
        TreeNode *a=rec(rt->left,p,q);
        TreeNode *b=rec(rt->right,p,q);
       
       if(a&&b) return rt;
        if(a)return a;
        if(b)return b;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca=NULL;
        lca= rec(root,p,q);
        return lca;
    }
};