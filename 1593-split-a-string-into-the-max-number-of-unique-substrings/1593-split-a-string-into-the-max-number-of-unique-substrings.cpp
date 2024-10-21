class Solution {
public:
    int rec(string &s,int i,map<string,bool>&mp){
        if(i==s.length())return 0;
        string t="";
        int ans=0;
        for(int j=i;j<s.length();j++){
            t+=s[j];
            if(mp[t])continue;
            mp[t]=1;
            ans=max(ans,rec(s,j+1,mp)+1);
            mp[t]=0;
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        map<string,bool>mp;
        return rec(s,0,mp);
    }
};