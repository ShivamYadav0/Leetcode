class Solution {
public:
    TreeNode* buildTree(vector<int>& a,int l,int r, vector<int>& b,int &i) {
		if(l>r)return NULL;
		TreeNode * node=new TreeNode(b[i]);
		i--;
		if(i<0)return node;
		int j=r;
		while(a[j]!=b[i+1])j--;
		node->right=buildTree(a,j+1,r,b,i);
		node->left=buildTree(a,l,j-1,b,i);
		return node;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int i=postorder.size()-1;
		return buildTree(inorder,0,inorder.size()-1,postorder,i);
	}
};
