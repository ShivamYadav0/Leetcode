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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& a) {
        vector<TreeNode*> ans;
        int n=a.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        while(!q.empty()){
            TreeNode *tmp=q.front().first;
            TreeNode *par=q.front().second;
            q.pop();
            if(mp.count(tmp->val)){
                if(par && par->left==tmp)  par->left=NULL;
                if(par && par->right==tmp) par->right=NULL;
                if(tmp->left) q.push({tmp->left,NULL});
                if(tmp->right) q.push({tmp->right,NULL});
            }else{
                if(tmp->left) q.push({tmp->left,tmp});
                if(tmp->right) q.push({tmp->right,tmp});
                if(par==NULL)    ans.push_back(tmp);
            }
        }
        return ans;
    }
};