class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
         int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(g[i][j]==1){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                        bool f=0;
                   int c=0;
                    
                    while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                        q.pop();
                    if(x==n-1||y==m-1||x==0||y==0)
                        f=1;
                    c++;
                    g[x][y]=2;
                    if(x+1<n &&g[x+1][y]==1){
                        g[x+1][y]=2;
                        q.push({x+1,y});
                    }
                    if(x>0 &&g[x-1][y]==1){
                        g[x-1][y]=2;
                        q.push({x-1,y});
                    }
                    if(y+1<m &&g[x][y+1]==1){
                        g[x][y+1]=2;
                        q.push({x,y+1});
                    }
                    if(y>0 &&g[x][y-1]==1){
                        g[x][y-1]=2;
                        q.push({x,y-1});
                    }
                    
                    }
                if(!f)ans+=c;
                }
            }
        }
        return ans;
    }
};