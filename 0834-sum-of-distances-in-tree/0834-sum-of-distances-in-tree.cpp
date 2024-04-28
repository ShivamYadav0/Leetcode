class Solution {
public:
vector<vector<int>>pre;
vector<vector<int>>g;
int post(int i,int c, vector<int>&p){
 
 int l=i;
 for(auto x:g[i]) {
   if(p[x]==-1){
    p[x]=i;
   if(l==i)
   l=post(x,c+1,p); 
   else 
   post(x,c+1,p);
   }
  }

 pre.push_back({i,l,c});
 return l;
}
    
 vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
  g.resize(n); 
  vector<int>p(n,-1);

 for(auto &x:edges){
 g[x[0]].push_back(x[1]);
  g[x[1]].push_back(x[0]);
 }
     int rt=0;
 p[0]=0;
  post(rt,0,p);
 
  unordered_map<int,int>mp; 
  vector<int>ps(n,0);
  ps[0]=pre[0].back();
  for(int i=0;i<pre.size();i++){
if(i>0)
ps[i]=ps[i-1]+pre[i].back();

   mp[pre[i][0]]=i;
 }
   vector<int>ans(n); 
 ans[rt]=ps[n-1];
  int in;
  for(int i=pre.size()-2;i>=0;i--){
 in=mp[pre[i][1]];
 ans[pre[i][0]]=ans[p[pre[i][0]]]-
2*(i-in+1)+n;
       
}
  return ans;
 }
};