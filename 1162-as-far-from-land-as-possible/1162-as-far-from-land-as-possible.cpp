struct node{
    int x;
    int y;
    int z;
    node(int a,int b,int c){
        x=a;
        y=b;
        z=c;
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>v(n,vector<int>(n,1e5));
        bool f=0,g=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    v[i][j]=0,f=1;
                else g=1;
            }
        if(!f||!g)return -1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    continue;
                else{
                    queue<node>q;
                    q.push({i,j,0});
                    while(!q.empty()){
                        node cur=q.front();
                        q.pop();
                     // cout<<cur.x<<" "<<cur.y<<" "<<cur.z<<endl;  
             if(cur.x<n-1&&1+cur.z<v[cur.x+1][cur.y]){
                 v[cur.x+1][cur.y]=1+cur.z;
                        q.push({cur.x+1,cur.y,cur.z+1});
             }
                        
             if(cur.x>0&&1+cur.z<v[cur.x-1][cur.y]){
                 v[cur.x-1][cur.y]=1+cur.z;
                        q.push({cur.x-1,cur.y,cur.z+1});
             }
                       
             if(cur.y<n-1&&1+cur.z<v[cur.x][cur.y+1]){
                 v[cur.x][cur.y+1]=1+cur.z;
                        q.push({cur.x,cur.y+1,cur.z+1});
             }
                        
             if(cur.y>0&&1+cur.z<v[cur.x][cur.y-1]){
                 v[cur.x][cur.y-1]=1+cur.z;
                        q.push({cur.x,cur.y-1,cur.z+1});
             }
                        
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,v[i][j])  ;
            }
    //            cout<<v[i][j]<<" ";
    //    cout<<endl;
        }
             //  ans=max(ans,v[i][j])  ;  
        return ans;
    }
};