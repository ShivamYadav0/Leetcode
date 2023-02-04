class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;
        unordered_map<char,int>mp;
        unordered_map<char,int>np;
        for(auto x:s1)mp[x]++;
        int j=0,k=0,i=0;
        
        for(;i<s1.length();i++){np[s2[i]]++;}
        bool f=1;
        for(auto [x,y]:mp)if(y!=np[x])f=0;
        if(f)return true;
        for(;i<s2.length();i++){
            
            np[s2[k]]--;
            np[s2[i]]++;
            k++;
           f=1;
        for(auto [x,y]:mp)if(y!=np[x])f=0;
        if(f)return true;
            
        }
        return false;
    }
};