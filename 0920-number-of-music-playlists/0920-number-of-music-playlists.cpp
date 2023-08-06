class Solution {
public:
    unordered_map<int,int>mp;
    vector<vector<int>>dp;
    int md=1e9+7;
    int rec(int g,int n,int k){
        
        if(g==0 ){
          
            return mp.size()==n;
        }
        if(dp[g][mp.size()]!=-1){
            return dp[g][mp.size()];
        }
        
        for(int j=1;j<=n;j++){
            if(mp.find(j)!=mp.end())
            mp[j]--;
        }
        
        long long ans=0;
        for(int j=1;j<=n;j++){
            if(mp.find(j)==mp.end()|| mp[j]<=0 ){
                int t=INT_MIN;
               if(mp.find(j)!=mp.end())
                   t=mp[j];
                mp[j]=k+1;
                ans+=rec(g-1,n,k)%md;
                if(t==INT_MIN)
                    mp.erase(j);
                else
                    mp[j]=t;
            }
        }
        
        for(int j=1;j<=n;j++){
            if(mp.find(j)!=mp.end())
            mp[j]++;
        }
        return dp[g][mp.size()]=ans%md;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        
       dp.resize(goal+1,vector<int>(n+1,-1));
       
        return rec(goal,n,k);
    }
};