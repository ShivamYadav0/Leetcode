class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int i=0;int j=1;
        int mx=0;
        for(auto x:arr)mx=max(x,mx);
        unordered_map<int,int>mp;
        while(j<arr.size()){
           
            if(arr[i]==mx) return mx;
            
            if(arr[i]>arr[j]){
              mp[arr[i]]++;
                j++;
            }
            else {
                mp[arr[j]]++;
                i=j;
                j++;
             
            }
            if(mp[arr[i]]==k)
                return arr[i];
            if(mp[arr[j]]==k)
                return arr[j];
        }
        return mx;
    }
};