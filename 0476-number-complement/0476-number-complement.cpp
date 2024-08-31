class Solution {
public:
    
    int findComplement(int num) {
        string s="";
        
        while(num){
            int rem= num%2;
            s+=('0'+rem);
            num=num/2;
        }
        // reverse(s.begin(),s.end());
        int p=0;
        int ans=0;
        cout<<s;
        for(auto itr: s){
            if(itr=='0'){
                ans+=pow(2,p);
            }
            p++;

        }
        return ans;

        
    }
};