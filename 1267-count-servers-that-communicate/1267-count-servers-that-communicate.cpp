class Solution {
public:
    unordered_map<int,int>mp;
    set<pair<int,int>>rank;
    
  
    int countServers(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            int x=-1,y=-1;
           
            for(int j=0;j<m;j++){
                 if(g[i][j]==1){
                     mp[i]++;
                     rank.insert({i,j});
                     //cout<<i <<" "<<j<<endl;
                     x=i,y=j;
                 }
            }
            if(mp[i]==1){
                rank.erase({x,y});
            }
        }
        mp.clear();
         for(int i=0;i<m;i++){
            int x=-1,y=-1;
            set<pair<int,int>>st;
            for(int j=0;j<n;j++){
                 if(g[j][i]==1){
                     mp[i]++;
                   st.insert({j,i});
                     x=j,y=i;
                 }
            }
            if(mp[i]>1){
               for(auto x:st){
                   rank.insert(x);
               }
            }
        }
        return (rank.size());
    }
};