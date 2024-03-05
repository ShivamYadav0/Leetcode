class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        int n=s.length();
        while(i<j){
           if(s[i]==s[j]){
               // cout<<i<<" "<<j<<endl;
            while(i<n-1&&s[i]==s[i+1]){
                i++;
            }
            while(j>0&&s[j]==s[j-1]){
                j--;
            }
               i++;
               j--;
           }
            else break;
        }
       
        return max(0,j-i+1);
    }
};