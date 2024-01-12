class Solution {
public:
    bool checkVovel(char c){
        vector<char>arr={'a','e','i','o','u','A','I','E','O','U'};
        auto it =  std::find(arr.begin(),arr.end(),c);
        return (it != arr.end());
    }
    bool halvesAreAlike(string s) {
        int c=0,m=0;
        for(int i=0;i<s.length();i++) {
          
            c+=checkVovel(s[i]);
              if(i<s.length()/2)
                m=c;
        }
       
        return c%2==0 && m==c/2;
    }
};