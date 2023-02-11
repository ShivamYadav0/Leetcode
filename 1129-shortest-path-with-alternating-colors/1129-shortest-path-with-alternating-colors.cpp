class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<pair<int,int>>g[n];
        for(auto x:redEdges){
            g[x[0]].push_back({x[1],0});
        }
        for(auto x:blueEdges){
            g[x[0]].push_back({x[1],1});
        }
       
        queue<pair<int,int>>q;
        q.push({0,-1});
        vector<int>dis(n,1e5);
        vector<int>vis(n,1e5);
        dis[0]=0;
        vis[0]=0;
        while(!q.empty()){
            int m=q.front().first;
            int f=q.front().second;
        
            q.pop();
            for(auto x:g[m]){
                if(f!=x.second&&
 ((x.second==0&&dis[m]+1<vis[x.first])||(x.second==1&&vis[m]+1<dis[x.first]))){
            
                    if(x.second==0)
                        vis[x.first]=dis[m]+1;
                       
                    else
                        dis[x.first]=vis[m]+1;
            
                    q.push({x.first,x.second});
                }
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=min(dis[i],vis[i]);
        }
            
        for(auto &x:ans)if(x==1e5)x=-1;
        
        return ans;
    }
};