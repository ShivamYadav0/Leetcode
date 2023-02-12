class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<long long,pair<int,int>>mp;
        for(int i=s.length()-1;i>=0;i--){
           long long a=0;
            int p=1;
            int n=min(int(s.length()-1),i+31);
            for(int j=i;j<=n;j++){
                a=a*2+(s[j]-'0');
                //p*=2;
               
                if(mp.find(a)!=mp.end()&&((mp[a].second-mp[a].first)>=j-i))
                mp[a]={i,j};
                
                else if(mp.find(a)==mp.end())mp[a]={i,j};
               //  cout<<a<<" "<<mp[a].first<<" "<<mp[a].second<<endl;
            }
        }
        vector<vector<int> >ans;
        for(auto x:queries){
               if(mp.find((x[0]^x[1]))!=mp.end())
                   ans.push_back({mp[(x[0]^x[1])].first,mp[(x[0]^x[1])].second});
            else ans.push_back({-1,-1});
        }
        return ans;
    }
};
