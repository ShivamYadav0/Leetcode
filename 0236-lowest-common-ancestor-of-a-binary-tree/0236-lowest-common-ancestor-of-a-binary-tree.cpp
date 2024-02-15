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
        TreeNode *a=rec(rt->left,p,q);
        TreeNode *b=rec(rt->right,p,q);
       
       if(rt==p){
           if(!a)
           a=rt;
           else if(!b)b=rt;
       }
     if(rt==q){
               if(!a)
           a=rt;
           else if(!b)b=rt;
        }
        if(a||b){
            if(!lca&&a&&b)
            lca=rt;
            return rt;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca=NULL;
         rec(root,p,q);
        return lca;
    }
};