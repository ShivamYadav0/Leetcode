class Solution {
public:
    
    int rec(int i,int n,vector<bool>&v){
        if(i>n)return 1;
        int ans=0;
       // cout<<i<<" ";
        for(int j=i;j<=n;j+=i){
            if(!v[j]){
            v[j]=1;
            ans+=rec(i+1,n,v);
            v[j]=0;
            }
        }
         for(int j=1;j<i;j++){
            if(i%j==0&&!v[j]){
            v[j]=1;
            ans+=rec(i+1,n,v);
            v[j]=0;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<bool>v(n+1,0);
        
            
        return rec(1,n,v);
    }
};