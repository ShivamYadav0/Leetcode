class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                 
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    long long t=nums[i];t+=nums[j];t+=nums[k];t+=nums[l];
                  //  cout<<t<<endl;
                    if(t<(long long)target){
                        k++;
                    }
                    else if(t>(long long)target){
                        l--;
                    }
                    else {
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                         k++;l--;
                    }
                    
                }
            }
        }
       vector<vector<int>>ans1;
        for(auto x:ans){
          //  for(auto y:x){
            //    cout<<y<<" ";
           // }
            ans1.push_back(x);
          //  cout<<endl;
        }
        return ans1;
    }
};