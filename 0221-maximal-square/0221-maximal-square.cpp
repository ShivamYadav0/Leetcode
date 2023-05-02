class Solution {
public:
     
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row[n][m];
        int col[n][m];
        int dp[n][m];
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<m;j++){
                dp[i][j]=0;
                if(matrix[i][j]=='1')c++;
                else c=0;
                row[i][j]=c;
            }
        }
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]=='1')c++;
                else c=0;
                col[j][i]=c;
            }
        }
        int mx=0;
        
        for(int i=0;i<m;i++)
            if(matrix[0][i]=='1')
            dp[0][i]=1,mx=1;
        for(int i=0;i<n;i++)
           if(matrix[i][0]=='1')
            dp[i][0]=1,mx=1;
        int dpp[m],u[m];
        for(int i=0;i<m;i++){
             dpp[i]=0,u[i]=0;
            if(matrix[0][i]=='1')
                u[i]=1;
        }
           
        for(int i=1;i<n;i++){
           dpp[0]=(matrix[i][0]=='1');
            for(int j=1;j<m;j++){
              int pv=min(row[i][j-1],col[i-1][j]);
                if(matrix[i][j]=='1')
                dpp[j]=min(u[j-1],pv)+1;
                else
                    dpp[j]=0;
                mx=max(mx,dpp[j]*dpp[j]);  
              //  cout<<dpp[j]<<" ";
                
            }
             
            for(int j=0;j<m;j++)
                u[j]=dpp[j];
             //u[0]=matrix[i][0]=='1';
            //cout<<endl;
        }
       // cout<<endl;
        return mx;
    }
};