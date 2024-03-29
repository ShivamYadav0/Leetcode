class Solution {
public:
    void print(unordered_map<char,int>mp){
        for(auto [x,y]:mp){
            cout<<x<<" "<<y<<" | ";
        }
        cout<<endl;
    }
    string minWindow(string s, string t) {
        
        unordered_map<char,int>u;
        vector<int>ans;
        int i=0,j=0,c=0;;
    
        for(auto x:t)u[x]++,c++;
       
        while(i<s.length()){
            
            if(u.find(s[i])!=u.end()){
                if(u[s[i]]>0)
                c--;
                u[s[i]]--;
            }
            
            if(c==0){
                while(j<i&&(u.find(s[j])==u.end()||u[s[j]]<0)){
                    if(u.find(s[j])!=u.end())u[s[j]]++;
                    j++;
                }
                if(ans.empty()||i-j<ans[1]-ans[0])
                ans={j,i};
            }
            i++;
            
        }
        if(ans.empty()) return "";
        return s.substr(ans[0],ans[1]-ans[0]+1);
    }
};