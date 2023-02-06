class Solution {
public:
    vector<string>ans;
    unordered_map<string,int>mp;
    void rec(string &s,int i,string t,bool f){
        if(i==s.length()){
            if(f)
            ans.push_back(t);
            return;
        }
        t+=s[i];
        int k=t.length();
        string v;
        while(k>0&&t[k-1]!=' '){
            v+=t[--k];
        }
        reverse(v.begin(),v.end());
        if(mp[v]>0){
        rec(s,i+1,t+(i+1<s.length()?" ":""),1);
        }
        rec(s,i+1,t,0);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict)mp[x]++;
        rec(s,0,"",0);
        return ans;
    }
};