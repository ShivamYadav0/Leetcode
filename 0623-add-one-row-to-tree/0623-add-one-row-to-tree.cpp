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
     TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *curr = new TreeNode(val);
            curr->left = root;
            return curr;
        }
        if(root==nullptr) return root;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty() and depth>2){
            int cnt = qu.size();
            for(int i=0;i<cnt;i++){
                TreeNode *curr = qu.front();
                qu.pop();
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            depth--;
        }
        while(!qu.empty()){
            TreeNode *curr = qu.front();
            qu.pop();
            if(curr->left){
                TreeNode *tmp = new TreeNode(val);
                tmp->left = curr->left;
                curr->left = tmp;
            }
            else{
                TreeNode *tmp = new TreeNode(val);
                curr->left = tmp;
            }
            if(curr->right){
                TreeNode *tmp = new TreeNode(val);
                tmp->right = curr->right;
                curr->right = tmp;
            }
            else{
                TreeNode *tmp = new TreeNode(val);
                curr->right = tmp;
            }
        }
        return root;
    }
  
};