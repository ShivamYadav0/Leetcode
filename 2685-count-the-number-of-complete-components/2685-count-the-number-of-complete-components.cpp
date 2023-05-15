class Solution {
public:
    vector<vector<int>>g;
   
     unordered_map<int,int>np;
   void rec(int i,int & c,int &m){
        if(np[i]==0){
            m++,np[i]++;
        }
       else return;
       c+=g[i].size();
        for(auto x:g[i]){
                rec(x,c,m);
            }
        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         g.resize(n);
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(np[i])continue;
            int c=0;
            int m=0;
            rec(i,c,m);
           // cout<<c<<" "<<m<<endl;
            if(c==m*(m-1))ans++;
            
        }
        return ans;
    }
};