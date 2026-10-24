#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 100000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll extgcd(ll a, ll b, ll &x, ll &y){
  int d = a;
  if(b != 0){
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }else{
    x = 1; y = 0;
  }
  return d;
}
ll mod_inv(ll a, ll M){
  ll x, y;
  extgcd(a, M, x, y);
  return (M + x % M) % M;
}
ll FACT[2001], IFACT[2001];
ll binomial(ll n, ll r){
  if(n < 0 || r < 0 || r > n)return 0;
  if(r > n / 2)r = n - r;
  return FACT[n]*IFACT[n-r]%MOD*IFACT[r]%MOD;
}

int main(){
  FACT[0] = 1; IFACT[0] = 1;
  for(int i = 1; i <= 2000; i++){
    FACT[i] = (FACT[i - 1] * i) % MOD;
    IFACT[i] = mod_inv(FACT[i], MOD);
  }
  int r, c, a1, a2, b1, b2;
  ll k = 1;
  cin>>r>>c>>a1>>a2>>b1>>b2;
  int y = abs(b1 - a1);
  if(y == r - y) k *= 2;
  else if(y > r - y) y = r - y;
  int x = abs(b2 - a2);
  if(x == c - x) k *= 2;
  else if(x > c - x) x = c - x;
  cout<<(k * binomial(x + y, x)) % MOD<<endl;
  return 0;
}