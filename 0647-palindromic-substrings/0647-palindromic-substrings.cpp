class Solution {
public:
    int check(string&s,int i,int j){
       
        while(i>=0&&j<s.length()&&s[i]==s[j]){
            i--;
            j++;
            
        }
        return (j-i)>>1;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans+=check(s,i,i)+check(s,i,i+1);
        }
        return ans;
    }
};