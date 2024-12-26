class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pv=prices[0];
        int ans=0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]>=prices[i]){
                
            }
            else {
                ans+=prices[i]-pv;
                pv=prices[i+1];
            }
        }
        if(prices.back()>=pv){
            ans+=prices.back()-pv;
        }
        return ans;
    }
};