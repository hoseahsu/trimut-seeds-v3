#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int E = 8;
const int INF = 1 << 29;

struct data{
  int n,ebit,r,c;
};

struct event{
  int a,b,c;
};

int n,m,e,s,t,r;
vector<int> ev[N];
vector<int> G[N];
event v[E];
  int d[N][N][1<<E];

int dijk(){
  queue<data> Q;
  data u,u2;

  for(int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<(1<<E);k++) d[i][j][k] = INF;
  d[s][0][0] = 0;
  u = (data){s,0,0,0};
  for(int i=0;i<ev[s].size();i++){
    u.ebit |= 1 << ev[s][i];
  }
  
  for(Q.push(u); !Q.empty();){
    u = Q.front();
    Q.pop();

    if(u.n == t) return u.c;
    if(u.r >= r) {
      u2 = (data){s, u.ebit, 0, u.c+1};
      if(d[u2.n][u2.r][u2.ebit] > u2.c){
        d[u2.n][u2.r][u2.ebit] = u2.c;
        Q.push(u2);
      }
      continue;
    }
    
    for(int i=0;i<G[u.n].size();i++){
      u2 = (data){G[u.n][i], u.ebit, u.r+1, u.c+1};
      for(int j=0;j<ev[u2.n].size();j++){
        u2.ebit |= 1 << ev[u2.n][j];
      }
      if(d[u2.n][u2.r][u2.ebit] > u2.c){
        d[u2.n][u2.r][u2.ebit] = u2.c;
        Q.push(u2);
      }
    }

    for(int i=0;i<e;i++){
      if((u.ebit & (1 << i)) == 0 || v[i].a != u.n && v[i].b != u.n) continue;
      u2 = (data){v[i].a, u.ebit, u.r+1, u.c+1};
      if(u.n == v[i].a) u2.n = v[i].b;
      for(int j=0;j<ev[u2.n].size();j++){
        u2.ebit |= 1 << ev[u2.n][j];
      }
      if(d[u2.n][u2.r][u2.ebit] > u2.c){
        d[u2.n][u2.r][u2.ebit] = u2.c;
        Q.push(u2);
      }
    }

    u2 = (data){s, u.ebit, 0, u.c+1};
    if(d[u2.n][u2.r][u2.ebit] > u2.c){
      d[u2.n][u2.r][u2.ebit] = u2.c;
      Q.push(u2);
    }
  }

  return -1;
}

void solve(){
  cout << dijk() << endl;
}

int main(){
  while(cin >> n >> m >> e >> s >> t >> r){
    for(int i=0;i<n;i++) G[i].clear(), ev[i].clear();

    for(int i=0;i<m;i++){
      int a,b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    for(int i=0;i<e;i++){
      cin >> v[i].a >> v[i].b >> v[i].c;
      ev[v[i].c].push_back(i);
    }
    solve();
  }
}