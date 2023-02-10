int n=(1<<15);
class Solution {
public:
    
    vector<int>dp;
    int rec(vector<string>& words, vector<int>v, vector<int>& score,int mask){
        
        if(dp[mask]!=-1)return dp[mask];
        int mx=0;
        for(int i=0;i<words.size();i++){
            if(mask&(1<<i))continue;
                 int s=0;
            vector<int>u=v;
            for(auto y:words[i]){
                if(u[y-'a']>0)s+=score[y-'a'],u[y-'a']--;
                else {s=-1;break;}
            }    
            if(s==-1) continue;
            mx=max(mx,rec(words,u,score,mask|(1<<i))+s);

        }
        return dp[mask]=mx;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>v(26,0);
        for(auto x:letters)v[x-'a']++;
        vector<int>u(26,0);
       /* u=v;
        int ans=0,s=0;
        for(auto x:words){
            s=0;
            
            for(auto y:x){
               // cout<<score[y-'a']<<" ";
                if(v[y-'a']>0)s+=score[y-'a'],v[y-'a']--;
                else {s=0;break;}
            }
            cout<<endl<<x<<" "<<s<<endl;
            ans+=s;
            v=u;
        }*/
        dp.resize(n,-1);
        return rec(words,v,score,0);
    
    }
};