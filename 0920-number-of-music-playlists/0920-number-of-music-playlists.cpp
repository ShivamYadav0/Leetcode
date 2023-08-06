
long long md=1e9+7;
class Solution {
public:
  vector<vector<long long>>dp;
    
 long long rec(int g,int k,int pi,int n, vector<int>&v,unordered_map<int,int>&mp){
     if(g==0) {
        // cout<<mp.size()<<endl;
         return mp.size()==n;
       }
     
     
     if(dp[g][mp.size()]!=-1)
         return dp[g][mp.size()];
   if(pi!=n)
    for(int i=0;i<n;i++)
       if(i!=pi)v[i]--;
   long long ans=0;
   for(int i=0;i<n;i++){
       
     if(v[i]<=0){
         int pv=v[i];
        v[i]=k;
         mp[i]++;
        ans+=rec(g-1,k,i,n,v,mp)%md;
         ans%=md;
         mp[i]--;
         if(mp[i]==0)
             mp.erase(i);
         //ans++;
        v[i]=pv;
         
      }
       
    }
     if(pi!=n)

    for(int i=0;i<n;i++)

       if(i!=pi)v[i]++;
     
     return dp[g][mp.size()]=ans;
     
  }
    int numMusicPlaylists(int n, int goal, int k) {
       vector<int>v(n,0);
       dp.resize(goal+2, vector<long long>(n+2,-1));
        unordered_map<int,int>mp;
       // cout<<endl;
      return  rec(goal,k,n,n,v,mp);
    }
};