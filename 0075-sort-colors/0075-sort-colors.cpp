class Solution {
public:
    void sortColors(vector<int>& n) {
  int i=0,j=0,k=n.size()-1;
  while(i<n.size()&& n[i]==0)i++;

  while(k>=0 && n[k]==2)k--;
   j=i;
  while(j<=k){
   while(k>=0 && n[k]==2)k--;
  // while(i<n.size()&&n[i]==0)
 //  i++; 
   if(j>k) return; 
  // j=max(j,i);
   if(n[j]==2)
   swap(n[j],n[k]),k--; 
   if(n[j]==0)
   swap(n[i],n[j]),i++; 
   
   j++;
  }
    }
};