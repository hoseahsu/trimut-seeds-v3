#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define int long long
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

const int nn=512345;
ll bit[nn+1];

ll sum(int i){ ++i;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,ll x){ ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}
ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=MOD-1)+=MOD-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
vector<ll> fact,finv,inv;
ll comb(ll n,ll r){
  if(n<r||r<0)return 0;
  return fact[n]*finv[n-r]%MOD*finv[r]%MOD;
}
class Doralion{
  void Modinvs(vector<ll> &re,int n){
    re.resize(n+1); re[1]=1;
    for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i)%MOD;
  }
  void Facts(vector<ll> &re,int n){
    re.resize(n+1); re[0]=1;
    rep(i,n)re[i+1]=re[i]*(i+1)%MOD;
  }
  void Factinvs(vector<ll> &re,const vector<ll> &inv,int n){
    re.resize(n+1); re[0]=1;
    rep(i,n)re[i+1]=re[i]*inv[i+1]%MOD;
  }
public:
  Doralion(int n){
    Modinvs(inv,n);
    Facts(fact,n);
    Factinvs(finv,inv,n);
  }
} doralion(512345);

signed main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  ll n;
  cin>>n;
  vector<ll> p(n);
  rep(i,n) cin>>p[i];
  vector<ll> usd(n);
  for(ll a:p)if(a) usd[a-1]=1;
  vector<ll> ls(n+1),rs(n+1);
  rep(i,n){
    if(!usd[i]) ++ls[i];
    ls[i+1]+=ls[i];
  }
  rrep(i,n){
    if(!usd[i]) ++rs[i];
    rs[i]+=rs[i+1];
  }
  ll N=0;
  rep(i,n) if(!usd[i]) ++N;
  ll re=0;
  ll t=0;
  ll hoge=0;
  vector<int> uu;
  rep(i,n) if(!usd[i]){ hoge+=i; uu.pb(i);}
  rep(i,n){
    if(p[i]){
      ll tmp=ls[p[i]-1]*t%MOD*fact[N-1]%MOD;
      ll num=(p[i]-1-sum(p[i]-1))*fact[N]%MOD;
      (num+=MOD-tmp)%=MOD;
      (re+=fact[n-i-1]*num%MOD)%=MOD;
      hoge-=uu.end()-lower_bound(all(uu),p[i]-1);
      add(p[i]-1,1);
    }else{
      ll cnt=0;
      ll tmp=N*(N-1)/2%MOD*t%MOD*(N>1?fact[N-2]:0)%MOD;
      (re+=(hoge%MOD*fact[N-1]%MOD+MOD-tmp)%MOD*fact[n-i-1]%MOD)%=MOD;
      ++t;
    }
  }
  (re+=fact[t])%=MOD;
  cout<<re<<endl;
  return 0;
}
