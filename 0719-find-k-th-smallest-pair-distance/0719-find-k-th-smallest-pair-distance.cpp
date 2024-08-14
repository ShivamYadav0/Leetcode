class Solution {
public:
    int smallestDistancePair(vector<int>& n, int k) {
    sort(n.begin(),n.end());
    int l,r; 
    l=0,r=n[n.size()-1]-n[0]+1;
    
   while(l<=r){
    int m=(r+l)/2; 
    int j=0;
    int p=0;
  for(int i=0;i<n.size();i++){
while(j<n.size()&&n[j]-n[i]<=m) j++;
     j--;
      p+=(j-i);
    }
    if(p>=k) 
     r=m-1; 
    else 
     l=m+1;
   }
   return l;
  }
};