class Solution {
public:
  vector<vector<int>>g;
   
    int ans=-1;
 void rec(int n, vector<int>&v, vector<int>&vis,int c){
    vis[n]=1;
     v[n]=c;  
   for(auto x:g[n]){
     if(vis[x]&&v[x]){
       ans=max(c-v[x]+1,ans);
      }
     if(!vis[x]){
       //v[x]=c;
       rec(x,v,vis,c+1);
      // v[x]=0;
    }
  }
     v[n]=0;
     
}
    int longestCycle(vector<int>& edges) {
     g.resize(edges.size());
      for(int i=0;i<edges.size();i++){
          if(edges[i]!=-1)
      g[i].push_back(edges[i]);
      }
      vector<int>vis(edges.size(),0);
 vector<int>v=vis;
   for(int i=0;i<edges.size();i++){
     if(vis[i]) continue;
      // v[i]=1;
    rec(i,v,vis,1);
      // v[i]=0;
     
   }
        return ans;
    }
};