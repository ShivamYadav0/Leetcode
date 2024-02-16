class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        sort(arr.begin(),arr.end());
        vector<int>v;
        int i=0,j=0;
        while(i<arr.size()){
            int c=0;
            int vl=arr[i];
            while(i<arr.size()&&arr[i]==vl){
                c++;
                i++;
            }
            v.push_back(c);
        }
        
        sort(v.begin(),v.end());
        int c=0;
        for(auto x:v){
           //out<<x<<" ";
            k-=x;
            if(k<0)break;
            c++;
        }
    //  cout<<endl;
        return v.size()-c;
    }
};