}
void print()
{
// cout << st.size() << endl;
for (auto x : st)
{
cout << x << " ";
}
cout << endl;
for (auto x : lazy)
{
cout << x << " ";
}
cout << endl;
}
};
​
​
class Solution {
public:
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
long long mx=0;
for(auto x:buildings)
mx=max(mx,(long long)x[1]);
Segment tree(mx);
vector<int>v;
for(auto x:buildings){
tree.update(0,0,mx,x[0],x[1]-1,x[2]);
// if(v.back()!=x[0])
v.push_back(x[0]);
v.push_back(x[1]);
}
sort(v.begin(),v.end());
// cout<<tree.query(0,0,mx,24,mx);
vector<vector<int>> ans;
v.push_back(v.back()+1);
int pa=0;
for(int i=0;i<v.size()-1;i++){
if(v[i]==v[i+1])continue;
int ca= tree.query(0,0,mx,v[i],v[i+1]-1);
if(ans.size()==0){
ans.push_back({v[i],ca});
}
else if(pa!=ca){
ans.push_back({v[i],ca});
}
pa=ca;
}
return ans;
}
};**