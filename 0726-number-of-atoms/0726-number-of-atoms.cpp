class Solution {
public:
    string countOfAtoms(string formula) {

        map<string, int>mp;
        stack<pair<int, string>>st;
          stack<pair<int, string>>st2;
        int i = 0;
        unordered_map<int, int>np;
        while (i < formula.length()) {

            if (formula[i] == ')') {
                i++;
              //  continue;
                string s = "";
                while (i < formula.length() && (formula[i] >= '0' && formula[i] <= '9')) {
                    s += formula[i];
                    i++;
                }
                if (s.length() == 0) {
                    s = "1";
                }
                int si = stoi(s);
                
                while (st.top().second != "(") {
                    auto su = st.top();
                    st.pop();
                    st2.push(su);
                    auto tu = st.top();
                    st.pop();
                    st2.push(tu);
                  //  cout<<si<<" "<<np[su.first]<<endl;
                    np[su.first]=si*np[su.first];
                }
                st.pop();
                while(!st2.empty()){
                    st.push(st2.top());
                    st2.pop();
                }

            }
            else if (formula[i] == '(') {

                i++;
                st.push({st.size(), "("});
            }
            else {
                string t = "";
                t += formula[i];
                i++;
                while (i < formula.length() && (formula[i] >= 'a' && formula[i] <= 'z')) {
                    t += formula[i];
                    i++;
                }
                st.push({st.size(), t});

               // if (i == formula.length())continue;
                string s = "";
                while (i < formula.length() && (formula[i] >= '0' && formula[i] <= '9')) {
                    s += formula[i];
                    i++;
                }
                if (s.length() == 0) {
                    s = "1";
                }
                np[st.size()] = stoi(s);
                st.push({st.size(), s});

            }
        }
        string ans="";
        
          while(!st.empty()){
           auto su=st.top();
             st.pop();
            
            auto tu=st.top();
           
            st.pop();
              mp[tu.second]+=np[su.first];
              
        }
        for(auto [x,y]:mp){
            ans+=(x);
            if(y>1)
                ans+=to_string(y);
        }
        return ans;
    }
};