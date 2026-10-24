#include<bits/stdc++.h>
using namespace std;
using Int = long long;
const int MOD = 1e9+7;
template<typename T> 
struct BIT{
  int n;
  vector<T> bit;
  //1-indexed
  BIT():n(-1){}
  BIT(int n_,T d):n(n_),bit(n_+1,d){}
  
  T sum(int i){
    T s=bit[0];
    for(int x=i;x>0;x-=(x&-x))
      (s+=bit[x])%=MOD;
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      (bit[x]+=a)%=MOD;
  }
  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
  }
};

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> x(n),y(m);
  for(Int i=0;i<n;i++) cin>>x[i];
  for(Int i=0;i<m;i++) cin>>y[i];

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int i=0;i<n;i++){
    if(x[i]<y[0]||y[m-1]<x[i]) continue;
    Int k=lower_bound(y.begin(),y.end(),x[i])-y.begin();
    vp.emplace_back(x[i]-y[k-1],x[i]-y[k]);
  }
  sort(vp.begin(),vp.end());
  vp.erase(unique(vp.begin(),vp.end()),vp.end());

  vector<Int> b;
  b.emplace_back(0);
  for(auto p:vp)
    b.emplace_back(-p.second);
  
  sort(b.begin(),b.end());
  b.erase(unique(b.begin(),b.end()),b.end());

  map<Int, Int> mb;
  for(Int i=0;i<(Int)b.size();i++) mb[b[i]]=i;

  m=b.size();
  BIT<int> bit(m+1,0);
  bit.add0(0,1);
  
  for(auto p:vp){
    Int y=mb[-p.second];
    bit.add0(y,bit.sum0(y-1));
  }
  
  cout<<bit.sum0(m)<<endl;
  return 0;
}
