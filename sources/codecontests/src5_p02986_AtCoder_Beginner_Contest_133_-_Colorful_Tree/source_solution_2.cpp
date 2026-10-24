#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using E = tuple<int,int,ll>;
const ll inf = numeric_limits<ll>::max()/3;
const ll mod = 1e9 + 7;

int n;
vector<vector<E>> tree;

int depth[100010];
int par[100010][20];

void init_par_depth(int node,int d, int p){
  depth[node] = d;
  par[node][0] = p;
  for(E edge : tree[node]){
    int next,c;
    ll w;
    tie(next,c,w) = edge;
    if(next != p){
      init_par_depth(next,d+1,node);
    }
  }
}

void fill_par(int root){
  init_par_depth(root,0,-1);
  for(int i = 1;i < 20;++i){
    for(int node = 0;node < n;++node){
      if(par[node][i-1] == -1){
        par[node][i] = -1;
      } else {
        par[node][i] = par[par[node][i-1]][i-1];
      }
    }
  }
}

int lca(int a,int b){
  if(depth[b] > depth[a]){
    swap(a,b);
  }
  for(int i = 0;i < 20;++i){
    if((depth[a] - depth[b]) & (1 << i)){
      a = par[a][i];
    }
  }
  assert(depth[a] == depth[b]);
  if(a == b){
    return a;
  }
  for(int i = 19;i >= 0;--i){
    if(par[a][i] != par[b][i]){
      a = par[a][i];
      b = par[b][i];
    }
  }
  return par[a][0];
}

ll ans[100010];
ll cnt[100010];
ll sum[100010];
using Q = tuple<int,ll,int,ll>;
vector<vector<Q>> query;

void calc(int node,int p,ll dist){
  for(Q q : query[node]){
    int id,x;
    ll mult,y;
    tie(id,mult,x,y) = q;
    ans[id] += mult * (dist - sum[x] + cnt[x] * y);
  }

  for(E edge : tree[node]){
    int next,c,w;
    tie(next,c,w) = edge;
    if(next != p){
      cnt[c]++;
      sum[c] += w;
      calc(next,node,dist+w);
      cnt[c]--;
      sum[c] -= w;
    }
  }
}


int main(void){
  int q;
  cin >> n >> q;
  tree = vector<vector<E>>(n);
  for(int i = 0;i < n-1;++i){
    int a,b,c;
    ll w;
    scanf("%d %d %d %lld", &a, &b, &c, &w);
    --a;--b;
    tree[a].push_back(make_tuple(b,c,w));
    tree[b].push_back(make_tuple(a,c,w));
  }
  fill_par(0);

  query = vector<vector<Q>>(n);
  for(int i = 0;i < q;++i){
    int x,u,v;
    ll y;
    scanf("%d %lld %d %d", &x, &y, &u, &v);
    --u;--v;
    int a = lca(u,v);
    query[a].push_back(make_tuple(i,-2LL,x,y));
    query[u].push_back(make_tuple(i,1LL,x,y));
    query[v].push_back(make_tuple(i,1LL,x,y));
  }

  fill(ans,ans+100010,0LL);
  fill(cnt,cnt+100010,0LL);
  fill(sum,sum+100010,0LL);
  calc(0,-1,0);

  for(int i = 0;i < q;++i){
    printf("%lld\n", ans[i]);
  }
  return 0;
}
