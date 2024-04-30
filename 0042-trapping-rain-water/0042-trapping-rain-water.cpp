class Solution {
public:
    int trap(vector<int>& h) {
   int i=0,j=h.size()-1;
   int lm=-1,rm=-1;
   int ans=0;
   while(i<=j) 
   { 
    if(h[i]<h[j]) 
     { 
      if(lm<h[i]) 
        lm=h[i]; 
      else 
       ans+=lm-h[i]; 
      i++;}
    else 
     { 
      if(rm<h[j])
       rm=h[j];
       else 
       ans+=rm-h[j];
      j--;
    }
    //cout<<ans<<" ";
    }
    return ans;
   }
};