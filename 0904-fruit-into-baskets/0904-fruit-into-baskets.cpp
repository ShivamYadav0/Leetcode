#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mx=0;
        unordered_map<int,int> mp;
        int pi=0,c=0,id;
        int s=0;
        for(int i=0;i<fruits.size();i++){
            //cout<<i<<" "<<s<<endl;
            if(mp.find(fruits[i])==mp.end()){
                if(mp.size()==2){
                   mx=max(mx,s);
                  while(mp.size()==2){
                      s--;
                      mp[fruits[pi]]--;
                      if(mp[fruits[pi]]==0)
                          mp.erase(fruits[pi]);
                      pi++;
                  }

                }
                
                s++;
                mp[fruits[i]]++;
                
            }
            else s++ ,mp[fruits[i]]++;
            
        }
        mx=max(mx,s);
        return mx;
    }
};