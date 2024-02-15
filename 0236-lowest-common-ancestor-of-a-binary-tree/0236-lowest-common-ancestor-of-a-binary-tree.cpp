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
    vector<bool> rec(TreeNode *rt,TreeNode *p,TreeNode *q){
        if(!rt){
            vector<bool>emp(lim,0);
            return emp;
        }
        vector<bool>a=rec(rt->left,p,q);
        vector<bool>b=rec(rt->right,p,q);
        vector<bool>c=a;
        for(int i=0;i<lim;i++){
            c[i]=(a[i]||b[i]);
        }
        if(p==rt){
            c[0]=1;
        }
        else if(q==rt){
            c[1]=1;
        }
         for(int i=0;i<lim&&!lca;i++){
            if(!c[i])break;
             if(i==lim-1){
                 lca=rt;
             }
        }
        return c;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca=NULL;
         rec(root,p,q);
        return lca;
    }
};