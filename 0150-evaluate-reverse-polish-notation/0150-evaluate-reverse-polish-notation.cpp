class Solution {
public:
    int evalRPN(vector<string>& t) {
  stack<long long >s; 
   long long a,b; 
   string ch;
  
   for(auto x:t){
     if(x=="+" || x=="-" || x=="*" || x=="/"){

     b=s.top();s.pop();
     a=s.top();s.pop();
     if(x=="+")
     s.push(a+b);
     else if(x=="-")
     s.push(a-b);
     else if(x=="*")
     s.push(a*b);
     else 
     s.push(a/b);
    }
    else 
    s.push((long long )stoi(x));
   }
   return s.top();
  }
};