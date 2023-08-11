 struct node{
        int r;
        int c;
        int v;
     node (){}
     node (int a,int b,int d){
         r=a,c=b,v=d;
     }
};
   
class Compare{
public:
    bool operator() (node &a, node &b){
        return a.v<=b.v;
    }
};

class Solution {
public:
   
   
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<vector<int>>g(n,vector<int>(n,INT_MAX));
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    g[i][j]=0;
                }
            }
        }
        int dx[]={-1,0,0,1};
        int dy[]={0,1,-1,0};
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                if(x.first+dx[i]>=n || x.first+dx[i]<0||x.second+dy[i]>=n || x.second+dy[i]<0 )continue;
                if(g[x.first][x.second]+1<g[x.first+dx[i]][x.second+dy[i]]){
                    g[x.first+dx[i]][x.second+dy[i]]=g[x.first][x.second]+1;
                    q.push({x.first+dx[i],x.second+dy[i]});
                }
            }
        }
        priority_queue<node,vector<node>,Compare>pq;
        
        pq.push({0,0,g[0][0]});
        g[0][0]=-1;
        int ans=0;
        while(!pq.empty()){
            
            node y=pq.top();
            pq.pop();
           
            if(y.r==n-1&&y.c==n-1){
                ans=max(ans,y.v);
            }
            for(int i=0;i<4;i++){
             if(y.r+dx[i]>=n || y.r+dx[i]<0||y.c+dy[i]>=n || y.c+dy[i]<0 || g[y.r+dx[i]][y.c+dy[i]]==-1)continue;
                if(g[y.r][y.c]+1<g[y.r+dx[i]][y.c+dy[i]]){
                    
                    pq.push({y.r+dx[i],y.c+dy[i],min(y.v,g[y.r+dx[i]][y.c+dy[i]])});
                    g[y.r+dx[i]][y.c+dy[i]]=-1;
                }
            }
        }
        
        return ans;
    }
};