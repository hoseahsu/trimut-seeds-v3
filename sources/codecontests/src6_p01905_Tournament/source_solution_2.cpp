#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <functional>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using pci = pair<char, int>;
using vpci = vector<pci>;
using vb = vector<bool>;
#define out(S) cout<<(S)<<endl;
#define REP(i,b) for(int i=0;i<(b);i++)
#define rREP(i,b) for(int i=(b)-1;i>=0;i--)
#define FOR(i,a,b) for(size_t i=(a);i<(b);i++)
#define rFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define Foreach(item,collection) for(auto item:collection)
#define mod(i) ((i) % (ll)(1e9 + 7))
ll modpow(ll i, ll j) { ll tmp = 1; while (j) { if (j % 2)tmp = mod(tmp*i); i = mod(i*i); j /= 2; }return tmp; }
#define divmod(a,b) (mod(a * modpow((ll)b,(ll)(1e9 + 5))))
#define INF 1e10;

int main(){
  int M,N;
  cin>>N>>M;
  vector<int> v(M);
  REP(i,M)cin>>v[i];
  vector<bool> under;
  REP(i,N) under.push_back(true);

  for(auto item:v) under[item]=false;

  int cnt=0;
  while (under.size()!=1) {
    vector<bool> tmp;
    for(int i=0;i<under.size();i+=2){
      if(under[i]&&under[i+1]) cnt++;
      tmp.push_back(under[i]||under[i+1]);
    }
    under=tmp;
  }
  out(cnt);
  
	return 0;
}