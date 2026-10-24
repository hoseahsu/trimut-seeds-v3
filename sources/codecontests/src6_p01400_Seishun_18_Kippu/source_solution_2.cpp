#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
#include <list>
#include <ctime>
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int(a.size()))
#define F first
#define S second
const double pi=acos(-1);
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};

int n,m;

vector<PI> G[500];
bool vis[500];
map<string,int> ms2i;

int s2i(const string& in){
  int sz=SZ(ms2i);
  if(ms2i.count(in))return ms2i[in];
  return ms2i[in]=sz;
}

int dij(const string& from,const string&to){
  int go=s2i(to);
  memset(vis,0,sizeof(vis));

  priority_queue<PI>q;
  q.push(mp(0,s2i(from)));
  while(!q.empty()){
    int c=-q.top().F;
    int v=q.top().S;
    q.pop();
    if(vis[v])continue;
    vis[v]=true;
    if(v==go)return c;
    FOR(it,G[v]){
      if(vis[it->F])continue;
      q.push(mp(-c-it->S,it->F));
    }
  }
}

void solve(){
  string s,p,g;
  cin>>s>>p>>g;
  ms2i.clear();
  rep(i,n)G[i].clear();

  rep(i,m){
    string as,bs;
    int d,t;
    cin>>as>>bs>>d>>t;
    int a=s2i(as),b=s2i(bs);
    G[a].pb(mp(b,d/40+t));
    G[b].pb(mp(a,d/40+t));
  }
  cout<<dij(s,p)+dij(p,g)<<endl;
}

int main(){
  while(cin>>n>>m,n)solve();
}