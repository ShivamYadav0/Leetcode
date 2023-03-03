class Solution {
public:
    int strStr(string h, string n) {
 if(n.length()>h.length())
  return -1;
 vector<int>lps(n.size());
 int j=0;
for(int i=1;i<n.size();i++){

  while(j>0&&n[i]!=n[j])
  j=lps[j-1];
  
  if(n[i]==n[j])j++;
  lps[i]=j;
    
 }
 j=0;
 for(int i=0;i<h.size();i++){
  
   while(j>0 && h[i]!=n[j])
   j=lps[j-1] ;
 
  if(h[i]==n[j])
  j++;
  if(j==n.size())
  return i-j+1;
 }
  return -1;
 }
};