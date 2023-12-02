class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
 
        
       unordered_map<int,vector<int>>g;
       
        int i=0;
        for(auto x:routes){
            int p=x.back();
            for(auto y:x){
                
                g[y].push_back(i);
              
            }
            i++;
        }
       
        /*for(auto [x,y]:g){
            cout<<x<<"-";
            for(auto z:y)
                cout<<z<< " ";
            cout<<endl;
        }*/
        unordered_map<int,int>visn;
          unordered_map<int,int>visr;
        queue<pair<int,int>>q;
        q.push({s,0});
           visn[s]=1;
        int ans=-1;
        while(!q.empty()){
            i++;
           // if(i>20)
           //break;
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
             cout<<x<<" "<<y<<endl;
             if(x==t){
                 ans=y;
                  break;
             }
               
            for(auto z:g[x]){
                if(visr.find(z)!=visr.end()) continue;
                visr[z]=1;
                for(auto ze:routes[z]){
                     if(visn.find(ze)==visn.end()){
                    q.push({ze,y+1});
                    visn[ze]=1;
                       
                }
                
                }
               
            }
        }
      //  for(auto [x,y]:vis){
         //   cout<<x<<","<<y<<endl;
         //   for(auto z:y)
            //    cout<<z<< " ";
           // cout<<endl;
       // }
        return ans;
        
    }
};