class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0,j=mat.size()-1;
        int ans=0;
        while(i<mat.size()){
            ans+=mat[i][i]+(i!=j?mat[i][j]:0);
            i++;j--;
        }
        return ans;
    }
};