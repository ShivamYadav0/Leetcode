class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int n=num.size();
        int s=0,c=0;
        for(int i=0;i<n;i++){
            s=num[i]+c+k%10;
            c=s/10;
            s%=10;
            k/=10;
            num[i]=s;
        }
        
        c+=k;
        while(c>0){
        num.push_back(c%10);
            c/=10;
        }
        
        reverse(num.begin(),num.end());
        return num;
    }
};