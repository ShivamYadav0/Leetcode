class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         int sr=0 , er=n-1 , sc=0 , ec=n-1 ;
       vector< vector<int>>ans(n,vector<int>(n));
                       int c=1;
        while(sr<=er&&sc<=ec){
            for(int i=sc;i<=ec;i++){
                ans[sr][i]=c++;
            }
           
            sr++;
             if(sr>er||sc>ec)
                break;
            for(int i=sr;i<=er;i++){
                 ans[i][ec]=c++;
            }
            
            ec--;
             if(sr>er||sc>ec)
                break;
            for(int i=ec;i>=sc;i--){
                ans[er][i]=c++;
            }
             
            er--;
            if(sr>er||sc>ec)
                break;
            for(int i=er;i>=sr;i--){
                ans[i][sc]=c++;
            }
            sc++;
            
        }
        return ans;
    }
};