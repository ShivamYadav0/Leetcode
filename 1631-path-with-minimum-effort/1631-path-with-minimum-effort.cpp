struct node{
        int r;
        int c;
        int v;
    int u;
     node (){}
     node (int a,int b,int d,int e){
         r=a,c=b,v=d;u=e;
     }
};
   
class Compare{
public:
    bool operator() (node &a, node &b){
        return a.v>=b.v;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        int dx[]={-1,0,0,1};
        int dy[]={0,1,-1,0};
        
       
        priority_queue<node,vector<node>,Compare>pq;
        
        pq.push({0,0,0,g[0][0]});
        
        int ans=INT_MAX;
        while(!pq.empty()){
            
            node y=pq.top();
            pq.pop();
           
            if(y.r==n-1&&y.c==m-1){
                ans=min(ans,y.v);
                return ans;
            }
            if(y.v>=ans)
                continue;
            g[y.r][y.c]=-1;
            for(int i=0;i<4;i++){
             if(y.r+dx[i]>=n || y.r+dx[i]<0||y.c+dy[i]>=m || y.c+dy[i]<0 || g[y.r+dx[i]][y.c+dy[i]]==-1)continue;
                int diff= abs(g[y.r+dx[i]][y.c+dy[i]]-y.u);
                if(diff<ans){
                   
                    pq.push({y.r+dx[i],y.c+dy[i],max(y.v,diff),g[y.r+dx[i]][y.c+dy[i]]});
                    
                }
            }
                    
        }
        
        return ans;
    }
};