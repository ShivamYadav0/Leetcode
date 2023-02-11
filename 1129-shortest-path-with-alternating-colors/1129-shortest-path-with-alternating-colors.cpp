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
       /* for(int i=0;i<n;i++){
            cout<<i<<"-";
            for(auto x:g[i])
                cout<<x.first<<","<<x.second<<' ';
            cout<<endl;
        }
        cout<<endl;*/
        queue<vector<int>>q;
        q.push({0,-1,0});
        vector<int>dis(n,1e5);
        vector<int>vis(n,1e5);
        dis[0]=0;
        vis[0]=0;
        while(!q.empty()){
            int m=q.front()[0];
            int f=q.front()[1];
            int c=q.front()[2];
            q.pop();
            for(auto x:g[m]){
                if(f!=x.second&&
 ((x.second==0&&c+1<vis[x.first])||(x.second==1&&c+1<dis[x.first]))){
                    if(x.second==0)
                        vis[x.first]=c+1;
                    else
                        dis[x.first]=c+1;
            
                    q.push({x.first,x.second,c+1});
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