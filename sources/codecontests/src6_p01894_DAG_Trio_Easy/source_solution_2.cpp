#include <bits/stdc++.h>
#define int long long
#define N 1000
#define V_MAX 1000
using namespace std;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
 
 
class TSort{
public:
  int V;
  vector<set<int> > in,out;
  vector<int> sorted;
  TSort(){V = -1,sorted.push_back(-1);}
  TSort(int V){
    in.resize(V);
    out.resize(V);
    sorted.push_back(-1);
    this->V = V;
  }
   
  void add_edge(int from,int to){
    assert(from < V && to < V);
    assert(out[from].count(to) == 0);
    assert(in[to].count(from) == 0);
    out[from].insert(to);
    in[to].insert(from);
  }
 
  void erase_edge(int from,int to){
    out[from].erase(to);
    in[to].erase(from);
  }
 
  void sort(){
    assert(sorted.size() && sorted[0]==-1 && "sort method is already invoked");
    sorted.clear();
    queue<int> Q;
    for(int i=0;i<V;i++)if(in[i].empty()) Q.push(i);
 
    while(!Q.empty()){
      int v = Q.front();Q.pop();
      sorted.push_back(v);
      for(int nx:out[v]){
        if(in[nx].size() == 1) Q.push(nx);
        in[nx].erase(v);
      }     
    }
     
    for(int i=0;i<V;i++) if(!in[i].empty()) sorted.clear(); // exist loop
  }
};
 

class Bridges{
public:
  typedef pair<int,int> P;
  int V;                  //テ」ツδ偲」ツδシテ」ツδ嘉ヲツ閉ー
  vector <int> G[V_MAX];  //テ」ツつーテ」ツδゥテ」ツδ陛」ツ?ョテゥツ堋」テヲツ篠・テ」ツδェテ」ツつケテ」ツδ暗」ツつ津ィツ。ツィテァツ渉セ
  set <P> bridges; // テヲツゥツ?
  int ord[V_MAX];         //ティツ。ツ古」ツ?催」ツ?凝」ツ?妥ゥツ??」ツつ津」ツ?づ」ツつ湘」ツつ嘉」ツ?凖」ツ??
  int low[V_MAX];         //
 
  Bridges(){V = -1;}
  Bridges(int V){this->V = V;}
   
  void add_edge(int a,int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }
 
  void erase_edge(int a,int b){
    for(int i=0;i<(int)G[a].size();i++) if(G[a][i] == b) {G[a].erase(G[a].begin()+i);break;}
    for(int i=0;i<(int)G[b].size();i++) if(G[b][i] == a) {G[b].erase(G[b].begin()+i);break;}
  }
 
  void dfs(int u, int p, int &c){
    ord[u] = low[u] = c++;
    
    for(int v:G[u]){
      if(v == p)continue;
      if(ord[v] == -1){
        dfs(v,u,c);
        low[u] = min(low[u],low[v]);
      }
      else low[u] = min(low[u], ord[v]);
      if(ord[u] < low[v]) bridges.insert(P(min(u,v),max(u,v)));
    }
  }
  
  void bridge(){
    assert(V >= 0 && "Set number of node V");
    bridges.clear();
    int c = 0;
    memset(ord,-1,sizeof(ord));
    memset(low,0,sizeof(low));
    for(int i=0;i<V;i++) if(ord[i]==-1) dfs(i,-1,c);
  }
   
  bool isBridge(int u,int v){return bridges.count(P(u,v)) || bridges.count(P(v,u));}
};
 
set<int> G[N];
 
signed main(){
  int n,m;
  cin>>n>>m;
  TSort T(n);
  Bridges B(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;a--,b--;
    T.add_edge(a,b);
    B.add_edge(a,b);
    assert(G[b].count(a)== 0);
    G[a].insert(b);
  }
   
  int ans = 0;
  TSort origin = T;
  for(int from=0;from<n;from++)
    for(int to:G[from]){
      T = origin;
      B.bridge();
      if(B.isBridge(from,to)) continue;
      T.erase_edge(from,to);
      B.erase_edge(from,to);
      
      T.sort();
      B.bridge();
      
      if(T.sorted.size() && (int)B.bridges.size()>=2)ans = 1;
      
      T.add_edge(from,to);
      B.add_edge(from,to);
    }
  cout<<(ans?"YES":"NO")<<endl;
     
  return 0;
}