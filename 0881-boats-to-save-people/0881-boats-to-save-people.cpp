class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int j=0,c=0;
     for(int i=p.size()-1;i>=j;i--){
         
         if(p[i]+p[j]<=limit)
            j++;
         c++;
     }
        return c;
    }
};