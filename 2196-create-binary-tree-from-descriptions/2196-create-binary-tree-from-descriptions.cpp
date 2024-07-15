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
    TreeNode* create_binary_tree (unordered_map<int, vector<int>> &um, int root){

        if(root!=-1){
            TreeNode* newnode= new TreeNode(root);
            if(um.count(root)>0){
                //left child is at index 1, call create_binary_tree recursively.
                newnode->left = create_binary_tree(um, um[root][1]); 

                //right child is at index 0, call create_binary_tree recursively.
                newnode->right = create_binary_tree(um, um[root][0]);
            }
            return newnode;
        }
        return NULL;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        int n=descriptions.size();

        //map for parents and there children 
        //(vector[0]->right_child, vector[1]->left_child, )
        unordered_map<int, vector<int>> um;

        //this map we will use to find node with no parent, i.e root
        unordered_map<int, int> um_child;

        for(int i = 0; i < n; i++) {
            //if not in map initialize the vector with -1 value
            if(um.count(descriptions[i][0])==0)
                um[descriptions[i][0]] = vector<int>(2, -1); 
            
            //and add child at its index
            um[descriptions[i][0]][descriptions[i][2]] = descriptions[i][1];

            //also add all child node in this map
            um_child[descriptions[i][1]]=1;
        }

        //find root node, root node should not be present in um_child map, 
        // as we have addedd all the child nodes in this map.
        int root=NULL;
        for(int i=0;i<n;i++){
            if( um_child.count(descriptions[i][0]) == 0 ){
                root=descriptions[i][0]; break;
            }
        }

        //after getting root node call the create_binary_tree 
        //and return the answer.
        return create_binary_tree(um, root);
    }
};