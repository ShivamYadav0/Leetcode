class Solution {
public:
    map<char,string>mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

vector<string>v;

void rec(string &s,int id, string t) 

{

  if(id==s.size()) {

  v.push_back(t); return;}

 

    for(int j=0;j<mp[s[id]].size();j++) 

    { 

     

      rec(s,id+1,t+

mp[s[id]][j]);

    }

  

}

    vector<string> letterCombinations(string dt) {

    if(dt.size()==0) 

    return v;

    rec(dt,0,""); 

    return v;

    }

};