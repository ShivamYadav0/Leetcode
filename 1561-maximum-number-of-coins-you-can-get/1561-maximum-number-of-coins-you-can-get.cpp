class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i=0,j=piles.size()-1,k=piles.size()-2;
        
        int s=0;
        while(i<k){
            s+=piles[k];
            k-=2;i++;j-=2;
        }
        return s;
    }
};