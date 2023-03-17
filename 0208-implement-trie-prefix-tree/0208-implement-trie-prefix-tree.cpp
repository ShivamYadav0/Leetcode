struct Node {
    Node * ch[26];
    bool f=-1;
    
    Node (){
        f=0;
        for(auto &x:ch)x=NULL;
    }
    
};


class Trie {
public:
    Node * trie;
    Trie() {
        trie=new Node();
    }
    
    void insert(string word) {
        Node * cur=trie;
        for (auto x:word){
            if(cur->ch[x-'a']==NULL)
           cur->ch[x-'a']=new Node();
            
            cur=cur->ch[x-'a'];
        }
       cur->f=1;
    }
    
    bool search(string word) {
         Node * cur=trie;
        if(cur==NULL) return false;
        for (auto x:word){
           // cout<<cur->ch[x-'a']->f<<endl;
            if(cur->ch[x-'a']!=NULL)
            cur=cur->ch[x-'a'];
            else 
                return false;
            
        }
        
      // return 0;
       return true&&(cur->f);
    }
    
    bool startsWith(string prefix) {
         Node * cur=trie;
         if(cur==NULL) return false;
        for (auto x:prefix){
           // cout<<cur->f<<endl;
            if(cur->ch[x-'a'])
            cur=cur->ch[x-'a'];
            else 
                return false;
            
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */