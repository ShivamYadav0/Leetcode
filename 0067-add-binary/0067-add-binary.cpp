class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(),a.end());
         reverse(b.begin(),b.end());
        string ans;
        int s=0,c=0,i=0;
        int j=min(a.length(),b.length());
        while(i<j){
            if(a[i]==b[i]&&a[i]=='1'){
                s=c;
                c=1;
            }
            else if(a[i]==b[i]&&a[i]=='0'){
                s=c,c=0;
            }
            else s=1-c;
            ans+=to_string(s);
            i++;
        }
        
        while(i<a.length()){
            if(a[i]=='1'){
                s=1-c;
            }
            else s=c,c=0;
            ans+=to_string(s);
            i++;
        }
         while(i<b.length()){
            if(b[i]=='1'){
                s=1-c;
            }
            else s=c,c=0;
            ans+=to_string(s);
            i++;
        }
        if(c==1){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};