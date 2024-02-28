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
    int ans=-1;
    int xy=1e9;
    int h=-1;
    int ht(TreeNode *rt){
        if(!rt)return 0;
        int l=ht(rt->left);
        int r=ht(rt->right);
        
        return max(l,r)+1;
    }
    bool rec(TreeNode*rt,int x,int y){
        if(!rt) return 0;
        if(!(rt->left)&& !(rt->right)){
            if(h==y){
              //  xy=rt->val;
                ans=rt->val;
                return 1;
            }
        }
        if(rec(rt->left,x-1,y+1))return 1;
        if(rec(rt->right,x+1,y+1))return 1;
        return 0;
    }
    int findBottomLeftValue(TreeNode* root) {
        h=ht(root);
        rec(root,0,1);
        return ans;
    }
};