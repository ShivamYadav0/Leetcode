class Solution {
public:
    int maxLength(vector<string>& arr,string str="",int index = 0) {
        
        unordered_set<char> s(str.begin(),str.end());

        if(s.size() != str.length()){
            return 0;
        }

        int rel = str.length();

        for(int i=index;i<arr.size();i++){
            rel = max(rel,maxLength(arr,str+arr[i],i+1));
        }

        return rel;
    }
};