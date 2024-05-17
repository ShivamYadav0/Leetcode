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
    bool f=0;
    TreeNode * rec(TreeNode *rt,int t){
        if(!rt)return NULL;
        
        if(rt->val==t&&rt->left==NULL&&rt->right==NULL){
            f=1;
            return NULL;
        }
        rt->left=rec(rt->left,t);
        rt->right=rec(rt->right,t);
        
        return rt;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        f=1;
        
        while(f){
            f=0;
            root=rec(root,target);
        }
        return root;
    }
};