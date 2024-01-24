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
    unordered_map<int,int>mp;
    int rec(TreeNode *rt){
        if(!rt) return 0;
        if(!(rt->left)&&!(rt->right)){
            mp[rt->val]++;
            int c=0;
            int k=0;
            for(auto [x,y]:mp){
             //   cout<<"{"<<x<<","<<y<<"} , ";
                if(y>0)k++;
                if(y%2)c++;
            }
            mp[rt->val]--;
           // cout<<endl;
            return c<2&&k>0;
        }
        mp[rt->val]++;
        int ans=0;
        ans=rec(rt->left);
        ans+=rec(rt->right);
        mp[rt->val]--;
       // if(mp[rt->val]==0)mp.erase(rt->val);
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
       // cout<<endl;
       return rec(root);
    }
};