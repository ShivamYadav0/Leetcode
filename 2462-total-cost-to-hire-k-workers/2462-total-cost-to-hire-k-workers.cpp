class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
   multiset<int>s1;

  multiset<int>s2;

  

 int s=candidates;

 int l=costs.size()-s;

    

for(int i=0;i<s;i++)

 

   s1.insert(costs[i]);

    

for(int i=l;i<costs.size();i++)

if(i>=s)

s2.insert(costs[i]);

  

  long long ans=0;

    l--;

   while(k-- >0){

  if(!s1.empty() && (s2.empty()|| *s1.begin()<= *s2.begin())){

  ans+= *s1.begin();

  s1.erase(s1.begin());

  if(s<=l)

  s1.insert(costs[s++]);

 

}

else if(!s2.empty()){

 ans+= *s2.begin();

 s2.erase(s2.begin());

 if(l>=s)

 s2.insert(costs[l--]);

 }

   }

   return ans ;


    }
};