class Solution {
public:
    vector<vector<int>>dp;
    vector<int>dpp;
    int rec(vector<int>&arr,int i,int p,int k){
        if(i==arr.size()){
             return 0;
        }
        if(dpp[i]!=-1)return dpp[i];
        int ans=0;
       
         int mx=arr[i];
        for(int j=i;j<arr.size()&&j<i+k;j++){
            mx=max(mx,arr[j]);
             int l=rec(arr,j+1,i,k)+(j-i+1)*mx;
            ans=max(ans,l);
        }
        return dpp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size()+1,vector<int>(k+1,-1));
        dpp.resize(arr.size()+1,-1);
        return rec(arr,0,-1,k);
    }
};