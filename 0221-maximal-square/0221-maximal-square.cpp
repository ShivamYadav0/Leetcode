class Solution {
public:
     
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mx=0;
        int dpp[m],u[m];
        for(int i=0;i<m;i++){
             dpp[i]=0,u[i]=0;
            if(matrix[0][i]=='1')
                u[i]=1,mx=1;
        }
           
        for(int i=1;i<n;i++){
           dpp[0]=(matrix[i][0]=='1');
            if(dpp[0])mx=max(mx,1);
            for(int j=1;j<m;j++){
              
                if(matrix[i][j]=='1')
                dpp[j]=min(u[j-1],min(dpp[j-1],u[j]))+1;
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