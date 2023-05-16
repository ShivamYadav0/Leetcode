class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l=0,h=2*1e9;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=0;
        while(l<=h){
            int m=(l+h)>>1;
            int p=0;
            bool f=1;
            for(int i=0;i<houses.size();i++){
                while(p<heaters.size()-1&&heaters[p]<=houses[i])p++;
               
if(abs(houses[i]-heaters[p])>m&&(p==0||abs(houses[i]-heaters[p-1])>m))
    f=0;
   
            }
            if(f){
                ans=m;
                 h=m-1;
            }
               
            else
                l=m+1;
        }
        return ans;
    }
};