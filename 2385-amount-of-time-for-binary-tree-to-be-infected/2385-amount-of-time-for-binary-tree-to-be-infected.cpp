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
    vector<TreeNode*>path;
    int mx=0;
     void find(TreeNode *rt,int i,int h){
         if(!rt){
             mx=max(mx,h);
             return;}
         
        
             bool ll=i<path.size()&&rt->left==path[i];
             bool tt=i<path.size()&&rt->right==path[i];
         
             find(rt->left,i+ll,ll?h-1:h+1);
             find(rt->right,i+tt,tt?h-1:h+1);
         
     }
    bool track(TreeNode*rt,int s){
        if(!rt) return false;
        if(rt->val==s){
            path.push_back(rt);
            return true; 
        }
        path.push_back(rt);
        if(track(rt->left,s)||track(rt->right,s)){
            return true;
        }
          path.pop_back();
        return false;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        track(root,start);
        /*for(auto x:path){
            cout<<x->val<<" ";
            
        }
        cout<<endl;*/
        find(root,1,path.size()-1);
        return mx-1;
        
    }
};