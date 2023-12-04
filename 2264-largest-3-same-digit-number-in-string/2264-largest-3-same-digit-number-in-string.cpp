class Solution {
public:
    string largestGoodInteger(string num) {
        
        int p=-1,c=0;
        int j=0;
        int ans=-1;
        for(int i=0;i<3;i++){
            if(p!=num[i]-'0')p=num[i]-'0',c=1;
            else c++;
        }
        if(c==3) ans= max(ans,p);
        for(int i=3;i<num.length();i++){
          //  cout<<p<<ans<<c<<endl;
            if(p==num[j]-'0'&&c>2){
                c--;
            }
            if(p!=num[i]-'0')p=num[i]-'0',c=1;
            else c++;
           if(c==3) ans= max(ans,p);
            j++;
        }
        string s="";
        if(ans!=-1){
            s=to_string(ans)+to_string(ans)+to_string(ans);
               
        }
        return s;
    }
};