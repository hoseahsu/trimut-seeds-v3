#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ii = pair<long long int, long long int>;
class prioritize {
 public:
  bool operator()(ii &p1, ii &p2) { return p1.first < p2.first; }
};
auto start_time = high_resolution_clock::now();
void time() { return; }
void ojudge() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return;
}
int main() {
  ojudge();
  long long int n;
  cin >> n;
  vector<ii> point(4 * n + 1);
  for (long long int i = 0; i < 4 * n + 1; i++) {
    cin >> point[i].first >> point[i].second;
  }
  sort((point).begin(), (point).end());
  map<long long int, long long int> mp[2];
  for (long long int i = 0; i < 4 * n + 1; i++) {
    mp[0][point[i].first]++;
    mp[1][point[i].second]++;
  }
  vector<long long int> x, y;
  for (auto it : mp[0]) x.push_back(it.first);
  for (auto it : mp[1]) y.push_back(it.first);
  vector<long long int> xb, yb;
  for (long long int i = 0; i < 4 * n + 1; i++) {
    xb.push_back(point[i].first);
    yb.push_back(point[i].second);
  }
  sort((xb).begin(), (xb).end());
  sort((yb).begin(), (yb).end());
  for (long long int i = 0; i < 4 * n + 1; i++) {
    long long int xx = point[i].first, yy = point[i].second;
    if ((mp[0][xx] == 1 && (xx == xb[0] || xx == xb[4 * n])) ||
        (mp[1][yy] == 1 && (yy == yb[0] || yy == yb[4 * n]))) {
      cout << xx << " " << yy << "\n";
      return 0;
    }
  }
  for (long long int i = 0; i < 4 * n + 1; i++) {
    long long int xx = point[i].first, yy = point[i].second;
    if (xx < xb[0] || xx > xb[4 * n] || yy < yb[0] || yy > yb[4 * n] ||
        ((xx > xb[0] && xx < xb[4 * n]) && (yy > yb[0] && yy < yb[4 * n]))) {
      cout << xx << " " << yy << "\n";
      return 0;
    }
  }
  time();
  return 0;
}
