class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int>mp;
        for(auto x:chars){
            mp[x]++;
            
        }
        int s=0;
        unordered_map<char,int>np;
        for(auto x:words){
            np.clear();
          
            
            if(np.size()<=mp.size()) {
                bool check=true;
                for(auto y:x){
                    np[y]++;
                    if(mp[y]<np[y]){ check=false; break;}
                }
                if(check)s+=x.length();
            }
        }
        return s;
    }
};