class Solution {
public:
    long long mod=1e9+7;
    long long extgcd(long long a, long long b, long long& x, long long& y) {
        long long d = a;
        if (b != 0) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        }
        else {
            x = 1; y = 0;
        }
        return d;
    }
    long long mod_inverse(long long a, long long m){
        long long x,y;
        long long g=extgcd(a,m,x,y);
        return(m+x%m)%m;
    }
    int numOfWays(vector<int>& nums) {
        
        long long fact[1002],ifact[1002];
        fact[0]=ifact[0]=1;

        for(int i=1; i<1002; i++)
        {
            fact[i]=i*fact[i-1]%mod;
            ifact[i]=mod_inverse(fact[i],mod);
        }

        int n=nums.size();
        int left[n],right[n],sz[n];

        for(int i=0; i<n; i++)
        {
            left[i]=right[i]=-1;
            sz[i]=1;
        }

        int nd;
        for(int i=1; i<n; i++)
        {
            nd=0;
            while(1)
            {
                if(nums[i]>nums[nd])
                {
                    if(right[nd]==-1)
                    {
                        right[nd]=i;
                        break;
                    }
                    else nd=right[nd];
                }
                else
                {
                    if(left[nd]==-1)
                    {
                        left[nd]=i;
                        break;
                    }
                    else nd=left[nd];
                }
            }
        }
        long long ans[n];   
        for(int i=n-1; i>=0; i--)
        {
            ans[i]=0;
            if(left[i]!=-1)sz[i]+=sz[left[i]];
            if(right[i]!=-1)sz[i]+=sz[right[i]];

            if(left[i]==-1 && right[i]==-1)
            {
                ans[i]=1;
            }
            else if(left[i]==-1)ans[i]=ans[right[i]];
            else if(right[i]==-1)ans[i]=ans[left[i]];
            else
            {
                ans[i]=ans[left[i]]*ans[right[i]]%mod;
                ans[i]*=fact[sz[left[i]]+sz[right[i]]];
                ans[i]%=mod;
                ans[i]*=(ifact[sz[left[i]]]*ifact[sz[right[i]]]%mod);
                ans[i]%=mod;
            }
        }
        
        ans[0]-=1;
        ans[0]+=mod;
        ans[0]%=mod;
        return ans[0];
    }
};