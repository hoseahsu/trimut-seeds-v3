#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int nn, mm, r, k;
priority_queue<pair<long long, pair<int, int> > > pq;
pair<long long, pair<int, int> > temp;
int x[] = {0, 0, 1, -1, -1, -1, 1, 1};
int y[] = {1, -1, 0, 0, -1, 1, -1, 1};
long long cost(int n, int m) {
  int l = max(0, m - r + 1);
  int ri = min(mm - 1, m + r - 1);
  ri = ri - r + 1;
  int u = max(0, n - r + 1);
  int d = min(nn - 1, n + r - 1);
  d = d - r + 1;
  return (ri - l + 1) * 1LL * (d - u + 1);
}
unordered_map<int, int> fr[N];
double ans;
int main(int argc, char const *argv[]) {
  ans = 0.0;
  cin >> nn >> mm >> r >> k;
  pq.push(make_pair(cost(nn / 2, mm / 2), make_pair(nn / 2, mm / 2)));
  fr[nn / 2][mm / 2] = 1;
  while (k--) {
    temp = pq.top();
    ans += (temp.first * 1.0);
    pq.pop();
    for (int i = 0; i < 8; i++) {
      if (temp.second.first + x[i] < nn && temp.second.second + y[i] < mm &&
          temp.second.first + x[i] >= 0 && temp.second.second + y[i] >= 0 &&
          (!fr[temp.second.first + x[i]][temp.second.second + y[i]])) {
        pq.push(make_pair(
            cost(temp.second.first + x[i], temp.second.second + y[i]),
            make_pair(temp.second.first + x[i], temp.second.second + y[i])));
        fr[temp.second.first + x[i]][temp.second.second + y[i]] = 1;
      }
    }
  }
  ans /= ((nn - r + 1) * 1.0 * (mm - r + 1));
  printf("%.12f\n", ans);
  return 0;
}
