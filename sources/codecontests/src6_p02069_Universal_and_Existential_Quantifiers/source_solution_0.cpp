#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;
ll P;
vector<ll> L,R;

int main(){
  cin>>N>>P;
  L.resize(N);
  R.resize(N);
  for(int i=0;i<N;i++) cin>>L[i]>>R[i];

  for(int i=0;i<N;i++) R[i]--;
  P--;

  vector<pair<ll,int>> l;
  for(int i=0;i<N;i++) l.push_back(mkp(L[i],i));
  sort(l.begin(),l.end());

  ll now=0;
  int pos=0;
  vector<ll> lef;
  while(now<=P){
    ll ma=now;
    while(pos<N&&l[pos].first<=now){
      int tar=l[pos].second;
      ma=max(ma,R[tar]);
      pos++;
    }
    lef.push_back(ma);
    now=ma+1;
  }

  vector<ll> v;
  for(int i=0;i<N;i++){
      v.push_back(L[i]);
      v.push_back(R[i]+1);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());

  map<ll,int> mp;
  for(int i=0;i<v.size();i++) mp[v[i]]=i+1;

  vector<int> imos((int)v.size()+1,0);
  for(int i=0;i<N;i++){
      imos[mp[L[i]]]++;
      imos[mp[R[i]+1]]--;
  }
  for(int i=1;i<=v.size();i++) imos[i]+=imos[i-1];

  int x=lef.size();
  int y=N;
  for(int i=1;i<v.size();i++) y=min(y,imos[i]);

  cout<<x<<" "<<N-y+1<<endl;

  return 0;
}

