#include<bits/stdc++.h>

using namespace std;


typedef long long int64;

int N, M, W[100000];
vector< int > g[100000];

bool v[100000];
int order[100000], low[100000], ptr;
int64 sum[100000], ans[100000];
vector< int > tree[100000];

void dfs(int idx, int par)
{
  v[idx] = true;
  order[idx] = ptr++;
  low[idx] = order[idx];
  sum[idx] = W[idx];
  for(auto &to : g[idx]) {
    if(!v[to]) {
      dfs(to, idx);
      low[idx] = min(low[idx], low[to]);
      sum[idx] += sum[to];
      tree[idx].emplace_back(to);
    } else if(to != par) {
      low[idx] = min(low[idx], order[to]);
    }
  }
}

void dfs2(int idx, int64 parcost)
{
  bool art = false;
  int64 all = parcost;
  if(idx == 0) {
    if(tree[idx].size() > 1) art = true;
    else art = false;
  } else {
    for(auto &to : tree[idx]) art |= order[idx] <= low[to];
  }
  for(auto &to : tree[idx]) all += sum[to];
  if(art) {
    int64 latte = parcost, malta = 0;
    for(auto &to : tree[idx]) {
      if(order[idx] <= low[to]) malta = max(malta, sum[to]);
      else latte += sum[to];
    }
    ans[idx] = max(latte, malta);
  } else {
    ans[idx] = sum[0] - W[idx];
  }
  for(auto &to : tree[idx]) dfs2(to, all + W[idx] - sum[to]);
}

int main()
{
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> W[i];
  }
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(0, -1);
  dfs2(0, 0);
  for(int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
}