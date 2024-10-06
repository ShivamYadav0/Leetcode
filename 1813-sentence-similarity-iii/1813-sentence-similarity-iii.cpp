class Solution {
public:
    vector<string> sepSpace(const string &str) {
        vector<string> ele;
        stringstream ss(str);
        string s;
        while (ss >> s) {
            ele.push_back(s);
        }
        return ele;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() > sentence2.size()) {
            return areSentencesSimilar(sentence2, sentence1);
        }
        
        vector<string> str1 = sepSpace(sentence1);
        vector<string> str2 = sepSpace(sentence2);
        
        int s=0;
        int e1=str1.size()-1;
        int e2= str2.size()-1;
        
        //prefix words
        while (s <= e1 && str1[s] == str2[s]) {
            s++;
        }
        
        //suffix words
        while (s <= e1 && str1[e1] == str2[e2]) {
            e1--;
            e2--;
        }
        
        return (s>e1);
    }

};