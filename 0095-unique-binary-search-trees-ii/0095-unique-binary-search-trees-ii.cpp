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
    
    vector<TreeNode*> buildBST(int left, int right)

{


    vector<TreeNode*> arr;


    if (left > right) {

        arr.push_back(NULL);

        return arr;

    }


    for (int i = left; i <= right; i++) {


        vector<TreeNode*> leftSubtrees = buildBST(left, i - 1);


        vector<TreeNode*> rightSubtrees = buildBST(i + 1, right);


        for (auto it : leftSubtrees) {

            for (auto ij : rightSubtrees) {

                TreeNode* root = new TreeNode(i);

                root->left = it;

                root->right = ij;

                arr.push_back(root);

            }

        }

    }

    return arr;

}
    vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*>v; 
    if(n==0) 
    return v; 
    
    return buildBST(1,n);
    }
};