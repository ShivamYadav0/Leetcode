class Solution {
public:
    
    void merge(vector<int>& v,int i,int m,int j){
        //cout<<i<<" "<<j<<endl;
        vector<int>t;
        int x=i,y=m+1;
        while(x<=m&&y<=j){
            if(v[x]<=v[y]){
                t.push_back(v[x++]);
            }
            else
                t.push_back(v[y++]);
        }
         while(x<=m){
            
                t.push_back(v[x++]);
        }
         while(y<=j){
            
                t.push_back(v[y++]);
        }
        for(int k=0;k<t.size();k++){
            v[i+k]=t[k];
        }
        
    }
    void mergesort (vector<int>&v,int i,int j){
        
        if(i>=j)return;
        int m=(i+j)/2;
        mergesort(v,i,m);
        mergesort(v,m+1,j);
        merge(v,i,m,j);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        mergesort(nums,0,nums.size()-1);
        return nums;
        
    }
};