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
    vector<int>v,u;
    void rec(TreeNode *rt){
        if(!rt) return;
        if(!rt->left and !rt->right){
            v.push_back(rt->val);
            return;
        }
        rec(rt->left);
        rec(rt->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        rec(root1);
        u=v;
        v.clear();
        rec(root2);
        if(u.size()!=v.size()) return false;
        for(int i=0;i<u.size();i++){
            if(u[i]!=v[i])return false;
        }
        return true;
    }
};