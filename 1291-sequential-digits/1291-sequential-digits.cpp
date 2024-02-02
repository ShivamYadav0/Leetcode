class Solution {
public:
    int dp[12][2][11];
    int lll;
    vector<int>ans;
    int rec(string &s,int i,int p,bool f,int num){
        if(i==s.length()){
            if(num>=lll)
            ans.push_back(num);
            return 1;
        }
        
        int tt=f?s[i]-'0':9;
        int ans=0;
        if(p==-1)
        for(int j=0;j<=tt;j++){
           ans+= rec(s,i+1,j==0?-1:j,j==tt&&f,num*10+j);
        }
        else if(tt>p)
            ans=rec(s,i+1,p+1,f&&p+1==tt,num*10+p+1);
        return ans;
    }
    vector<int> sequentialDigits(int low, int high) {
        memset(dp,-1,sizeof(dp));
        string a=to_string(high);
        string b=to_string(low-1);
        lll=low;
        int r=rec(a,0,-1,1,0);
       // memset(dp,-1,sizeof(dp));
       // int l=rec(b,0,-1,-1,0);
        return ans;
    }
};