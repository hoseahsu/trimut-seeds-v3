#include <bits/stdc++.h>
using namespace std;
const int NMax = 100005;
int N, Q, Father[NMax];
double P[NMax], SonSum[NMax], sum, ans;
vector<int> G[NMax];
void readEdge() {
  int x, y;
  scanf("%d%d", &x, &y);
  ++x;
  ++y;
  G[x].push_back(y);
  G[y].push_back(x);
}
void readProb() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%lf", &P[i]);
    P[i] = 1 - P[i];
    sum += P[i];
  }
}
void readGraph() {
  for (int i = 1; i < N; i++) {
    readEdge();
  }
}
void buildSonSum(int node, int father) {
  Father[node] = father;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i];
    if (neighb == father) continue;
    buildSonSum(neighb, node);
    SonSum[node] += P[neighb];
  }
}
double firstAns() {
  double res = 0.0;
  for (int i = 1; i <= N; i++) res += P[i] * SonSum[i];
  return sum - res;
}
void update(int node, double newP) {
  ans += P[Father[node]] * SonSum[Father[node]] + P[node] * SonSum[node];
  SonSum[Father[node]] += newP - P[node];
  ans -= P[Father[node]] * SonSum[Father[node]];
  ans += newP - P[node];
  P[node] = newP;
  ans -= P[node] * SonSum[node];
}
void Solve() {
  ans = firstAns();
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    int node;
    double val;
    scanf("%d%lf", &node, &val);
    update(node + 1, 1 - val);
    printf("%.10lf\n", ans);
  }
}
int main() {
  readProb();
  readGraph();
  buildSonSum(1, 0);
  Solve();
  return 0;
}
