class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
          vector<int>dp(n,0);
        dp[n-1]=1;
        int ans=1;
         vector<int>dpp(n,0);
        dpp[n-1]=n-1;
        int idd=0;
        for(int i=n-2;i>=0;i--){
            dp[i]=1;
            dpp[i]=i;
            int id=i;
            for(int j=n-1;j>i;j--){
                if(nums[j]%nums[i]==0&&dp[i]<dp[j]+1){
                    
                        dp[i]=dp[j]+1;
                    dpp[i]=j;
                    
                }
               // dp[i]=max(dp[i],dp[j]+1);
            }
            if(ans<dp[i]){
                ans=dp[i];
                idd=i;
            }
          //  ans=max(ans,dp[i]);
        }
        vector<int>uu={nums[idd]};
        
        while(dpp[idd]!=idd){
            uu.push_back(nums[dpp[idd]]);
            idd=dpp[idd];
        }
        //cout<<idd<<endl;
        return uu;
    }
};