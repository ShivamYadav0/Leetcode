class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
    
        if(s1.length()>s2.length())return {};
        unordered_map<char,int>mp;
        unordered_map<char,int>np;
        int n=s1.length();
        vector<int>v;
        for(auto x:s1)mp[x]++;
        int j=0,k=0,i=0;
        
        for(;i<s1.length();i++){np[s2[i]]++;}
        bool f=1;
        for(auto [x,y]:mp)if(y!=np[x]){f=0;break;}
        if(f)v.push_back(i-n);
        for(;i<s2.length();i++){
                     
            np[s2[k]]--;
            np[s2[i]]++;
            k++;    
           f=1;   
          for(auto [x,y]:mp)if(y!=np[x]){f=0;break;}
          if(f)v.push_back(i-n+1);
        }
        
        return v;
    
    }
};