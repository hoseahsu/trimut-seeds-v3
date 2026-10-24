#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long n, m, t, k;
int pos[200005], tmp[200005];
pair<pair<int, int>, int> a[200005];
class dsu {
 public:
  int fa[200005];
  void init(int n) {
    for (int i = 0; i <= n; i++) {
      fa[i] = i;
    }
  }
  int find(int u) {
    while (u != fa[u]) u = fa[u] = fa[fa[u]];
    fa[u] = u + 1;
    return u;
  }
} num;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.second != b.first.second) return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}
set<int> mp;
vector<pair<pair<long long, long long>, int>> points;
void print(int p[200005]) {
  for (int i = 1; i <= n; i++) cout << p[i] << " ";
  cout << endl;
}
void swp(int a, int b) {
  for (int i = 1; i <= n; i++) {
    tmp[i] = pos[i];
    if (tmp[i] == a) {
      tmp[i] = b;
    } else if (tmp[i] == b) {
      tmp[i] = a;
    }
  }
}
bool cmp2(pair<pair<long long, long long>, int> a,
          pair<pair<long long, long long>, int> b) {
  if (a.first.first != b.first.first) return a.first.first < b.first.first;
  return a.second < b.second;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i + 1;
  }
  sort(a, a + n, cmp);
  num.init(n);
  bool sud = 1;
  for (int i = 0; i < n; i++) {
    pos[a[i].second] = num.find(a[i].first.first);
    points.push_back({make_pair(pos[a[i].second], a[i].first.first), 0});
    points.push_back(
        {make_pair(a[i].first.second, a[i].first.first), pos[a[i].second]});
  }
  sort(points.begin(), points.end(), cmp2);
  for (auto point : points) {
    if (point.second == 0) {
      if (!mp.empty() && point.first.second <= (*mp.rbegin())) {
        swp((*mp.rbegin()), point.first.first);
        sud = 0;
        break;
      }
      mp.insert(point.first.first);
    } else {
      mp.erase(point.second);
    }
  }
  if (sud) {
    cout << "YES\n";
    print(pos);
  } else {
    cout << "NO\n";
    print(pos);
    print(tmp);
  }
  return 0;
}
