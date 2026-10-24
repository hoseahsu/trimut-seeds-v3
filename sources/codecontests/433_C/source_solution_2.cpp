#include <bits/stdc++.h>
using namespace std;
vector<int> info;
int n, m;
vector<int> nb[100001];
int diff(int a, int b) { return abs(a - b); }
int main(int argc, char const *argv[]) {
  cin >> n >> m;
  int aux;
  cin >> aux;
  info.push_back(aux);
  int prev = aux;
  long long turns = 0;
  for (int i = 1; i < m; ++i) {
    cin >> aux;
    info.push_back(aux);
    if (prev != aux) {
      nb[aux].push_back(prev);
      nb[prev].push_back(aux);
    }
    turns += diff(aux, prev);
    prev = aux;
  }
  long long maxchange = 0;
  long long change;
  for (int i = 1; i <= n; ++i) {
    sort(nb[i].begin(), nb[i].end());
    long long d = 0;
    long long dm = 0;
    for (int j = 0; j < nb[i].size(); ++j) {
      d += diff(i, nb[i][j]);
      dm += diff(nb[i][(nb[i].size()) / 2], nb[i][j]);
    }
    change = d - dm;
    if (change > maxchange) {
      maxchange = change;
    }
  }
  cout << turns - maxchange << endl;
  return 0;
}
