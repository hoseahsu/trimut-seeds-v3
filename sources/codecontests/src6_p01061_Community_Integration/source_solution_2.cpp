#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int>parent,sizes;
  UnionFind(int n):parent(n),sizes(n,1){
    for(int i=0;i<n;++i)parent[i]=i;
  }
  int find(int x){
    if(x==parent[x])return x;
    return parent[x]=find(parent[x]);
  }
  void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(sizes[x]>sizes[y])swap(x,y);
    parent[y]=x;
    sizes[x]+=sizes[y];
    sizes[y]=0;
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  int size(int x){
    return sizes[find(x)];
  }
};
int main(){
  int n,m,a,b,x=0,y=0;
  cin>>n>>m;
  UnionFind UF(n);
  for(int i=0;i++<m;UF.unite(--a,--b))cin>>a>>b;
  for(int i=0;i<n;++i)UF.sizes[i]>1?x++:UF.sizes[i]-1?:y++;
  cout<<abs(x-y)<<endl;
}