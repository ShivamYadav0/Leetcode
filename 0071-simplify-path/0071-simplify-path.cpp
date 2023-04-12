class Solution {
public:
    string simplifyPath(string path) {
        int c=0;
        string s="/";
        bool f=1;
        for(int i=1;i<path.length();i++){
            if(path[i]=='.' &&f){
                c++; 
            }
            else if(path[i]=='/'){
                if(c<=2){
                    
                    if(c==2){
                        bool x=1;
                        while(s.length()>0&&(s.back()!='/'||x)){
                            if(s.back()=='/')x=0;
                            s.pop_back();}
                        
                    }
                }
                else {
                    while(c>0){
                        s+='.';
                        c--;
                    }
                }
                 if(s.length()==0||s.back()!='/')
                    s+='/';
                c=0;
                f=1;
            }
            else{
                while(c>0){
                        s+='.';
                        c--;
                    }
                s+=path[i];
                c=0;
                f=0;
            }
                
        }
        if(c<=2){
                    if(c==2){
                        bool x=1;
                        while(s.length()>1&&(s.back()!='/'||x)){
                            if(s.back()=='/')x=0;
                            s.pop_back();}
                        
                    }
                }
                else {
                    while(c>0){
                        s+='.';
                        c--;
                    }
                }
         if(s.back()=='/'&&s.length()>1)
                    s.pop_back();
        return s;
    }
};