class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int arr[26];
        for(int i=0;i<26;i++)
            arr[order[i]-'a']=i;
        for(int i=1;i<words.size();i++){
            int j=0,n;
            n=min(words[i-1].length(),words[i].length());
            while(j<n){
                //cout <<words[i-1][j]<<words[i][j]<<endl;
                if(arr[words[i-1][j]-'a']>arr[words[i][j]-'a'])
                    
                    return false;
                if(arr[words[i-1][j]-'a']<arr[words[i][j]-'a'])
                    break;
                j++;
            }
            
            if(j==words[i].length()&&j!=words[i-1].length())return 0;
            
        }
        return 1;
    }
};