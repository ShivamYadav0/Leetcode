class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            int rem = nums[i]%k;
            if(rem>=0){
                mymap[rem]++;
            }
            else{
                mymap[k+rem]++;
            }
        }
        for(const auto& pair : mymap){
            if(pair.first==0){
                if(pair.second%2!=0)return false;
            }
            else{
                if(mymap.find(k-pair.first)==mymap.end())return false;
                else{
                    if(pair.second!=mymap[k-pair.first])return false;
                }
            }
        }
        return true;
    }
};