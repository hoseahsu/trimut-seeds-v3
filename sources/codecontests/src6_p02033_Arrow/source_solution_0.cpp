#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define AND(x,y,z) 
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define DUMPP(xs) for (auto x:xs) cout<<'('<<x.first<<','<<x.second<<')';cout<<endl
#define FOR(i,a,b) for (ll i=(ll)(a);i<(ll)(b);++i)
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)
#define YES(cond) cond ? OUT("YES") : OUT("NO")
#define Yes(cond) cond ? OUT("Yes") : OUT("No")

template<class T> T gcd(const T x,const T y){if(!y){return x;}return gcd(y,x%y);}
template<class T> T lcm(const T x,const T y){return x/gcd(x,y)*y;};
template<class T> T modpow(const T x,const T n,const T mod) {
  T res=1;while(n>0){if(n%2)res=res*x%mod;x=x*x%mod;n/=2;};return res;
}
template<class T> bool alltrue(const T &a){return all_of(ALL(a),[](bool x){return x;});}
template<class T> bool anytrue(const T &a){return any_of(ALL(a),[](bool x){return x;});}
template<class T> bool contain(const T &a,const T &b){for(auto x:b){if (a.find(x)==a.end()){return false;}}return true;}
template<class T> bool mmax(T &m,const T q){ if (m < q) {m = q; return true;} else return false; }
template<class T> bool mmin(T &m,const T q){ if (m > q) {m = q; return true;} else return false; }
template<class T> int siz(const T &a) {return (int)a.size();}
template<class T> set<T> devisers(T n) {
  set<T> res;for(T i=1;i<(T)sqrt(n)+1;i++){if(n%i==0){res.insert(i);res.insert(n/i);}}return res;
}
template<class T> void concat(T &a, const T &b){a.insert(a.end(),b.begin(),b.end());}
template<class T> void getand(const T &a,const T &b,T &c) {
  set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}
template<class T> void getor(const T &a,const T &b,T &c) {
  set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}

typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD=1e9+7;
const int MAX=1e5+100;

int main() {
  // 最短の矢の長さ（or-1）
  // 矢の長さをxとすると
  // l>=N-(x*M)を満たす最低のxが答え
  // N*l/M<=x
  // しかし当然ながら扇風機の範囲がかぶるところが存在する
  // xを順に伸ばして言ってDPに損失を保存していく
  int N,M;cin>>N>>M;
  vector<int> ms(M);
  REP(i,M) cin>>ms[i];

  // 損失にならない場はtrue
  bitset<100000> bs;
  REP(i,M) bs.set(N-1-(ms[i]-1));

  // 長さがiの時の損失の数をdp[i-1]とする
  vector<ll> dp(N,0);
  dp[0] = N-M;

  // 余計なzeroの数
  int red = 100000 - N;

  FOR(n,1,N) {
    bs |= bs>>1;
    dp[n] = 100000 - bs.count()-red;
  }
  // DUMP(dp);

  int Q;cin>>Q;

  // 逆順にして、l+1のlower_bound-begin-1=idxとしたとき、N-idxが答え
  reverse(ALL(dp));

  REP(i,Q) {
    int l;cin>>l;
    if (dp[0]>l) {
      OUT(-1);
    } else {
      ll idx = lower_bound(ALL(dp),l+1)-dp.begin()-1;
      OUT(N-idx);
    }
  }

  return 0;
}
