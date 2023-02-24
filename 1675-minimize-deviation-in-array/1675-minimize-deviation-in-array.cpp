class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
         vector<int>v=nums;
        int i=0;
        for (auto &x:nums){
            if(x%2) v[i]*=2;
            i++;
            while(x>1&&x%2==0)x/=2;
        }
       
        int mn=INT_MAX;
        int mx=INT_MIN;
         priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>pqs;
        
       //  priority_queue<int>pqg;
        i=0;
        for(auto x:nums){
            mx=max(mx,x);
            mn=min(mn,x);
            
            pqs.push({x,i++});
          //  pqg.push(x);
        }
        int ans=INT_MAX;
        while(!pqs.empty()){
            
            mn=pqs.top().first;
            int id=pqs.top().second;
           //  for(auto x:nums){
           //      cout<<x<<" ";}
           // cout<<endl;
            pqs.pop();
           
            ans=min(ans,mx-mn);
            if(nums[id]*2<=v[id]){
            pqs.push({mn*2,id});
                nums[id]*=2;
            mx=max(mx,2*mn);
            }
            else if(mn%2==0) break;
            
        }
       
        
        
        return ans;
    }
};