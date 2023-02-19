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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  vector<vector<int>> ans;

  if(root== NULL) return ans;

    queue<TreeNode*> q;

    q.push(root);
    bool fl=0;
  while(!q.empty()) {

    int size=q.size();
    int id=0;
    vector<int> level(size);

    for(int i=0;i<size; i++) {

TreeNode *node = q.front();

q.pop();

 if(node->left != NULL) q.push(node->left);

  if(node->right != NULL) q.push(node->right);
 fl==1?id=size-i-1:id=i;
level[id]=(node->val);

   }

  ans.push_back(level);
  fl=!fl;
  }

  return ans;
 }
};