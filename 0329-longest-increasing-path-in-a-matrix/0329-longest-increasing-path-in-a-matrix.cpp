class Solution {
public:
    vector<vector<int>>dp;
    int rec(vector<vector<int>>&v,int i,int j,int p){
      
        if(dp[i][j]!=-1){
           // cout<<i<<j<<dp[i][j]<<endl;
            return dp[i][j];
        }
        
        int mx=1;
        if(i+1<v.size()&&p<v[i+1][j]){
             mx=max(mx,rec(v,i+1,j,v[i+1][j])+1);
            //if(v[i][j]==0)
           // cout<<mx<<endl;
        }
        
        if(i>0&&p<v[i-1][j])
         mx=max(mx, rec(v,i-1,j,v[i-1][j])+1);
        if(j+1<v[0].size()&&p<v[i][j+1])
         mx=max(mx, rec(v,i,j+1,v[i][j+1])+1);
        if(j>0&&p<v[i][j-1])
         mx= max(mx,rec(v,i,j-1,v[i][j-1])+1);
       // if(v[i][j]==0)
       // cout<<mx<<endl;
        return dp[i][j]=mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),-1));
        int mx=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                
                mx=max(mx,rec(matrix,i,j,matrix[i][j]));
            }
        }
      /*  for(auto x:dp){
            for(auto y:x)
                cout<<y<<" ";
            cout<<endl;
        }
        cout<<endl;*/
        return mx;
    }
};