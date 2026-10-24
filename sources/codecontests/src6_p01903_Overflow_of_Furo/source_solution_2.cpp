#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__",", __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 100000000

template<typename T>
class MaximumFlow{
public:
  struct edge{int to; T cap; int rev;};
  vector<vector<edge> > Graph;
  vector<int> level, iter; //s??????????????¢,???????????§????????????
  void bfs(int s){
    fill(all(level), -1);
    queue<int> q;
    level[s]=0;
    q.push(s);
    while(!q.empty()){
      int v=q.front(); q.pop();
      for(auto e : Graph[v]){
        if(e.cap>0 && level[e.to]<0){
          level[e.to] = level[v]+1;
          q.push(e.to);
        }
      }
    }
  }
  T dfs(int v, int t, T f){
    if(v==t) return f;
    for(int &i=iter[v]; i<(int)Graph[v].size(); i++){
      auto &e = Graph[v][i];
      if(e.cap>0 && level[v]<level[e.to]){
        T d = dfs(e.to, t, min(f, e.cap));
        if(d>0){
          e.cap -= d;
          Graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  MaximumFlow(int n){
    Graph = vector<vector<edge> >(n, vector<edge>());
    level = vector<int>(n);
    iter = vector<int>(n);
  }
  T max_flow(int s, int t){
    T flow=0;
    while(true){
      bfs(s);
      if(level[t] < 0) break;
      fill(all(iter), 0);
      T f;
      while( (f=dfs(s,t,INF)) > 0){
        flow += f;
      }
    }
    return flow;
  }
  void add_edge(int from, int to, T cap){
    int tos = Graph[to].size(), froms = Graph[from].size();
    Graph[from].pb(((edge){to, cap, tos}));
    Graph[to].pb(((edge){from, cap, froms}));
  }
}; // END class MaximumFlow

int main(){
  int k,n,m;
  cin>>k>>n>>m;
  MaximumFlow<int> flow(k+n+2);
  // 0: sink
  // 1-k: gensen
  // k+1 - k+n: vertex
  // k+n+1: source
  rep(i,k) flow.add_edge(k+n+1, i+1, INF);

  bool ov = false;
  rep(i,m){
    int a,b,c;
    cin>>a>>b>>c;
    if(1<=a && a<=k && 1<=b && b<=k) continue;
    flow.add_edge(a, b, c);
    if(a*b==0 && ((1<=a && a<=k) || (1<=b && b<=k)) ) ov = true;
  }
  if(ov){ cout << "overfuro" << endl; return 0; }

  int f = flow.max_flow(k+n+1, 0);

  // source??????bfs??????????????????????£????????????¢???
  auto g = flow.Graph;
  vector<int> u,v;
  queue<int> q;
  vector<bool> visited(k+n+2);
  q.push(k+n+1);
  visited[k+n+1]=true;
  while(!q.empty()){
    int d = q.front(); q.pop();
    for(auto to : g[d]) if(!visited[to.to]){
      if(to.cap==0){u.pb(d); v.pb(to.to);}
      else{
        q.push(to.to);
        visited[to.to] = true;
      }
    }
  }
  // dbg(u);
  // dbg(v);

  vector<int> uu(k+n+2, -1), vv(k+n+2, -1);
  int ans = f;
  rep(i,u.size()){
    if(uu[u[i]]==-1 || vv[v[i]]==-1){
      flow.Graph = g;
      if(uu[u[i]]==-1){
        if(1<=u[i] && u[i]<=k) uu[u[i]] = INF;
        else uu[u[i]] = flow.max_flow(k+n+1, u[i]);
      }
      if(vv[v[i]]==-1){
        if(v[i]==0) vv[v[i]] = INF;
        else vv[v[i]] = flow.max_flow(v[i], 0);
      }
    }
//    dbg(uu[u[i]],vv[v[i]]);
    ans = max(ans, f + min(uu[u[i]], vv[v[i]]) );
  }
  cout << ans << endl;

  return 0;
}