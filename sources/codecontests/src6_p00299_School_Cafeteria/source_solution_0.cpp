#include<bits/stdc++.h>

using namespace std;

struct edge
{
  int u, v, cost;

  edge(int u, int v, int c) : u(u), v(v), cost(c) {}
};

const int INF = 1 << 30;

int main()
{
  int N, C;
  int A[200], O[200], B[200], S[200], D[200];

  auto bellman_ford = [&]()
  {
    vector< edge > edges;
    vector< int > v(N, INF), lastupdate(N, -1);
    v[0] = 0, lastupdate[0] = 0;

    for(int i = 0; i < C; i++) {
      if(O[i] == 1) swap(A[i], B[i]);
      edges.emplace_back(B[i], A[i], 0);
      if(S[i] == 0) edges.emplace_back(B[i], A[i], -D[i]);
      else edges.emplace_back(A[i], B[i], D[i]);
      if(O[i] == 1) swap(A[i], B[i]);
    }

    for(int i = 0; i <= N; i++) {
      for(auto &e : edges) {
        if(v[e.u] + e.cost < v[e.v]) {
          v[e.v] = v[e.u] + e.cost;
          lastupdate[e.v] = i;
        }
      }
    }

    int ret = 0;
    for(int i = 0; i < N; i++) {
      if(lastupdate[i] == N) return (-1);
      if(v[i] < 0) return (-1);
      ret = max(ret, v[i]);
    }
    return (ret);
  };

  cin >> N >> C;
  vector< int > undefined;
  for(int i = 0; i < C; i++) {
    string str;
    cin >> str;
    int tail = 0, a = 0, b = 0, o, s, d = 0;
    while(isdigit(str[tail])) a = a * 10 + str[tail++] - '0';
    if(str[tail] == '*') o = 2;
    else if(str[tail] == '<') o = 0, ++tail;
    else o = 1, ++tail;
    ++tail;
    while(isdigit(str[tail])) b = b * 10 + str[tail++] - '0';
    if(str[tail] == '+') s = 0;
    else s = 1;
    ++tail;
    while(tail < str.size()) d = d * 10 + str[tail++] - '0';
    A[i] = --a, B[i] = --b, O[i] = o, S[i] = s, D[i] = d;
    if(o == 2) undefined.push_back(i);
  }
  int ret = -1;

  for(int i = 0; i < (1 << undefined.size()); i++) {
    for(int j = 0; j < undefined.size(); j++) O[undefined[j]] = (i >> j) & 1;
    ret = max(ret, bellman_ford());
  }

  if(ret >= INF) cout << "inf" << endl;
  else cout << ret << endl;
}