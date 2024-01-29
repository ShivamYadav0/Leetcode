class Solution {
public:
    int lt=9;
    string ps="";
    
    long long dp[16][2];
    string tmp="";
    long long rec(string &s,int i , bool tt,bool fl){
        if(ps.length()>s.length())return 0;
        if(s.length()-i==ps.length()){
            //cout<<tmp<<fl<<" ";
            return !tt||(tt&&fl);
        }
        if(dp[i][tt]!=-1)return dp[i][tt];
        int ct=tt?min(s[i]-'0',lt):lt;
        if(tt&&s[i]-'0'>ct)tt=false;
        long long ans=0;
        for(int j=0;j<=ct;j++){
          //  tmp+=to_string(j);
            ans+=rec(s,i+1,tt&&j==ct,fl);
           // tmp.pop_back();
        }
        return dp[i][tt]=ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        lt=limit;
        ps=s;
        memset(dp,-1,sizeof(dp));
        string n1=to_string(finish);
        start--;
        string n2=to_string(start);
        
        bool ch1=false;
        int x=s.length()-1,y=n1.length()-1;
        if(y>=x){
            y=n1.length()-s.length();
            if(s<=n1.substr(y))ch1=true;
        }
       
        long long r=rec(n1,0,1,ch1);
       // cout<<endl;
        ch1=false;
          x=s.length()-1,y=n2.length()-1;
         if(y>=x){
            y=n2.length()-s.length();
            if(s<=n2.substr(y))ch1=true;
        }
     memset(dp,-1,sizeof(dp));
        long long l=rec(n2,0,1,ch1);
      //  cout<<endl;
        return r-l;
    }
};