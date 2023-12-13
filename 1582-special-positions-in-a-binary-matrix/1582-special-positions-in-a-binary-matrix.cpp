class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if(mat.size()==0) return 0;
        vector<int>rv(mat.size(),0);
        vector<int>cv(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                cv[j]++,rv[i]++;
            }
        }
        int c=0;
         for(int i=0;i<mat.size();i++){
             if(rv[i]>1) continue;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1&&cv[j]==1)
                c++;
            }
        }
        return c;
    }
};