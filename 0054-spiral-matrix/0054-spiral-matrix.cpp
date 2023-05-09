class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int sr=0 , er=matrix.size()-1 , sc=0 , ec=matrix[0].size()-1 ;
        vector<int>ans((er+1)*(1+ec));
                       int c=0;
        while(sr<=er&&sc<=ec){
            for(int i=sc;i<=ec;i++){
                ans[c++]=matrix[sr][i];
            }
           
            sr++;
             if(sr>er||sc>ec)
                break;
            for(int i=sr;i<=er;i++){
                 ans[c++]=(matrix[i][ec]);
            }
            
            ec--;
             if(sr>er||sc>ec)
                break;
            for(int i=ec;i>=sc;i--){
                ans[c++]=(matrix[er][i]);
            }
             
            er--;
            if(sr>er||sc>ec)
                break;
            for(int i=er;i>=sr;i--){
                ans[c++]=(matrix[i][sc]);
            }
            sc++;
            
        }
        return ans;
    }
};