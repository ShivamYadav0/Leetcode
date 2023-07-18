class LRUCache {
public:
    unordered_map<int,pair<int,int>>mp;
    map<int,int>cp;
    int c,cap,d;
    LRUCache(int capacity) {
        c=0;cap=capacity,d=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
       // cout<<key<<endl;
        cp.erase(mp[key].second);
        cp[c]=key;
        mp[key].second=c;
        c++;
        return mp[key].first;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
            cp.erase(mp[key].second);
        cp[c]=key;
        mp[key]={value,c++};
        if(mp.size()>cap){
            //cout<<key<<endl;
          auto  dp=cp.begin();
           // if(cp.find(d)!=cp.end())
                mp.erase(dp->second),cp.erase(dp->first);
          //  d++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */