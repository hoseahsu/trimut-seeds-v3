#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct QuickFind{
  Int n;
  vector<Int> r,p;
  vector<vector<Int> > v;
  QuickFind(){}
  QuickFind(Int sz):n(sz),r(sz),p(sz),v(sz){
    for(Int i=0;i<n;i++){
      r[i]=1,p[i]=i;
      v[i].resize(1,i);
    }
  }
  bool same(Int x,Int y){
    return p[x]==p[y];
  }
  void unite(Int x,Int y){
    x=p[x];y=p[y];
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    for(Int i=0;i<(Int)v[y].size();i++){
      p[v[y][i]]=x;
      v[x].push_back(v[y][i]);
    }
    v[y].clear();
  }
  Int find(Int v){return p[v];};
};

struct SCC{
  Int n;
  vector<vector<Int> > G,rG,T,C;
  vector<Int> vs,used,belong;
  SCC(){}
  SCC(Int sz):n(sz),G(sz),rG(sz),used(sz),belong(sz){}
  
  void add_edge(Int from,Int to){
    G[from].push_back(to);
    rG[to].push_back(from);
  }
  
  void input(Int m,Int offset=0){
    Int a,b;
    for(Int i=0;i<m;i++){
      cin>>a>>b;
      add_edge(a+offset,b+offset);
    }
  }
  
  void dfs(Int v){
    used[v]=1;
    for(Int i=0;i<(Int)G[v].size();i++){
      if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
  }
  
  void rdfs(Int v,Int k){
    used[v]=1;
    belong[v]=k;
    C[k].push_back(v);
    for(Int i=0;i<(Int)rG[v].size();i++){
      if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
  }
  
  Int build(){
    fill(used.begin(),used.end(),0);
    vs.clear();
    for(Int v=0;v<n;v++){
      if(!used[v]) dfs(v);
    }
    fill(used.begin(),used.end(),0);
    Int k=0;
    for(Int i=vs.size()-1;i>=0;i--){
      if(!used[vs[i]]){
	T.push_back(vector<Int>());
	C.push_back(vector<Int>());
	rdfs(vs[i],k++);
      }
    }
    for(Int i=0;i<n;i++)
      for(Int u:G[i])
	if(belong[i]!=belong[u])
	  T[belong[i]].push_back(belong[u]);
    for(Int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }
};

void inf(){
  cout<<"Infinite"<<endl;
  exit(0);
}

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

signed main(){
  Int n,m;
  cin>>n>>m;
  vector<Int> x(m),y(m),w(m);
  for(Int i=0;i<m;i++) cin>>x[i]>>y[i]>>w[i];
  QuickFind uf(n);
  vector<vector<Int> > G(n),H(n);
  for(Int i=0;i<m;i++){
    x[i]--;y[i]--;
    if(w[i]==2){
      if(uf.same(x[i],y[i])) inf();
      uf.unite(x[i],y[i]);
      G[x[i]].emplace_back(y[i]);
      G[y[i]].emplace_back(x[i]);
    }
  }

  vector<Int> v;
  for(Int i=0;i<n;i++)
    if(uf.find(i)==i) v.emplace_back(i);

  Int k=v.size();
  map<Int, Int> idx;
  for(Int i=0;i<k;i++) idx[v[i]]=i;

  SCC scc(k);
  for(Int i=0;i<m;i++){
    if(w[i]==2) continue;
    H[x[i]].emplace_back(y[i]);
    Int s=idx[uf.find(x[i])];
    Int t=idx[uf.find(y[i])];
    if(s==t) inf();
    scc.add_edge(s,t);
  }

  Int t=scc.build();
  if(t!=k) inf();

  vector<Int> dp1(n,0),dp2(n,0);
  vector<Int> vs;
  for(Int i=0;i<k;i++)
    vs.emplace_back(v[scc.C[i][0]]);

  reverse(vs.begin(),vs.end());

  function<Int(int,Int)> dfs=[&](Int v,Int p)->Int{
    Int res=dp1[v];
    for(Int u:G[v]){
      if(u==p) continue;
      chmax(res,dfs(u,v)+1);
    }
    return dp2[v]=res;
  };
  
  function<void(Int,int,Int)> dfs2=[&](Int v,Int p,Int d)->void{
    using P = pair<Int, Int>;
    vector<P> ds;
    ds.emplace_back(d,p);
    ds.emplace_back(dp1[v],v);
    for(Int u:G[v]){
      if(u==p) continue;
      ds.emplace_back(dp2[u]+1,u);
    }
    sort(ds.rbegin(),ds.rend());
    for(Int u:G[v]){
      if(u==p) continue;
      dfs2(u,v,ds[u==ds[0].second].first+1);
    }
    chmax(dp2[v],d);
  };
  
  for(Int x:vs){
    for(Int v:uf.v[x])
      for(Int u:H[v])
	chmax(dp1[v],dp2[u]+1);
    //cout<<x<<endl;
    dfs(x,-1);
    dfs2(x,-1,0);
  }

  if(0) 
    for(Int i=0;i<n;i++)
      cout<<i<<":"<<dp1[i]<<" "<<dp2[i]<<endl;
  
  Int ans=0;
  for(Int x:dp2) chmax(ans,x);
  cout<<ans<<endl;
  return 0;
}

