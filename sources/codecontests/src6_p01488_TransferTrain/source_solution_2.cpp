/*
  ad hocに修正を続けた結果えらいことになった...
*/
#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

#define MAX 100100

struct Edge {
  int dst;
  ll cost;
};

typedef pair<ll,ll> Cost;

struct Data {
  int cur, prev;
  Cost cost;
  bool operator < ( const Data &d ) const {
    if( cost != d.cost ) return cost > d.cost;
    return cur > d.cur;
  }
};

int V,sp, ep;
ll T;
Cost mini[MAX];

int par[MAX];
int find(int x) {
  if( x == par[x] ) return x;
  return par[x] = find(par[x]);
}
void unite(int x,int y) {
  x = find(x), y = find(y);
  if( x != y ) par[x] = y;
}

vector<Edge> G[MAX];
vector<int> additional_edges[MAX];
vector<string> svec;
bool goal[MAX];
map<string,int> mp;

const bool debug = 0;

void compute() {
  rep(i,V) par[i] = i;
  rep(i,V) rep(j,(int)additional_edges[i].size()-1) {
    int s = additional_edges[i][j];
    int t = additional_edges[i][j+1];
    unite(s,t);
  }
  if( debug ) {
    cout << "* V = " << V << endl;
    rep(i,V) cout << find(i) << " "; puts("");
  }
     
  
  rep(i,V) mini[i] = (Cost){LLONG_MAX, LLONG_MAX};
  priority_queue<Data> Q;
  rep(i,(int)additional_edges[sp].size()) Q.push((Data){additional_edges[sp][i], -1, Cost(0,0)});
  rep(i,(int)additional_edges[ep].size()) goal[additional_edges[ep][i]] = true;
    
  while( !Q.empty() ) {
    Data d = Q.top(); Q.pop();
    if( debug ) {
      cout << "d.cur = " << d.cur << ", d.cost = (" << d.cost.F << "," << d.cost.S << ")" << endl;
    }
    if( goal[d.cur] ) {
      cout << d.cost.F << " " << d.cost.S << endl;
      return;
    }
    // GO MY WAY
    rep(i,(int)G[d.cur].size()) {
      Edge &e = G[d.cur][i];
      if( mini[e.dst].F > d.cost.F + e.cost || ( mini[e.dst].F == d.cost.F + e.cost && mini[e.dst].S > d.cost.S ) ) {
	mini[e.dst] = Cost(d.cost.F+e.cost,d.cost.S);
	Q.push((Data){e.dst, -1, mini[e.dst]});
      }
    }

    if( d.prev == -1 ) { //乗り換えしたあとに乗り換えるのはだめ！ だめだから！！
      int uid = mp[svec[d.cur]];
      // 乗り換え
      rep(i, (int)additional_edges[uid].size()) {
	int dst = additional_edges[uid][i];
	if( mini[dst].F > d.cost.F + T || ( mini[dst].F == d.cost.F + T && mini[dst].S > d.cost.S + 1 ) ) {
	  mini[dst] = Cost(d.cost.F+T,d.cost.S+1);
	  Q.push((Data){dst, find(d.cur), mini[dst]});
	}
      }
    }
  }
  puts("-1");
}

inline int update(string &s, map<string,int> &mp) {
  if( mp.count(s) ) return mp[s];
  int id = mp.size();
  mp[s] = id;
  return id;
}

int main() {
  int N;
  cin >> N >> T;
  string ss, se, stmp;
  cin >> ss >> se;
  int n;
  int ID = 0;
  rep(_,N) {
    cin >> n;
    vector<int> vec;
    rep(i,n) {
      cin >> stmp;
      additional_edges[update(stmp,mp)].pb(ID);
      svec.pb(stmp);
      vec.pb(ID++);
    }
    int tmp;
    rep(i,n-1) {
      cin >> tmp;
      int s = vec[i], t = vec[i+1];
      G[s].pb((Edge){t,tmp});
      G[t].pb((Edge){s,tmp});
    }
  }
  V = ID;
  sp = update(ss,mp);
  ep = update(se,mp);
  if( debug ) {
    for(auto v : mp) {
      cout << "(" << v.first << ", " << v.second << ") " << endl;
    }
    cout << "* Infor for add" << endl;
    rep(i,V) {
      cout << "  * " << i << "-th:" << endl;
      cout << "    ";
      rep(j,(int)additional_edges[i].size()) {
	cout << additional_edges[i][j] << endl;
      }
    }
  }
  compute();
  return 0;
}

