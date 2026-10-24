#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  return (a.first == b.first) ? a.second < b.second : a.first < b.first;
}
long long int modInverse(long long int a) {
  long long int m = 1000000007;
  long long int y = 0, x = 1;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += 1000000007;
  return x;
}
long long int binpow(long long int a, long long int p) {
  if (p == 0) return 1;
  long long int ret = binpow(a, p / 2);
  ret *= ret;
  ret %= 1000000007;
  if (p % 2) {
    ret *= a;
    ret %= 1000000007;
  }
  return ret;
}
bool arr[7][7];
int conv(string in) {
  if (in == "Anka") return 0;
  if (in == "Chapay") return 1;
  if (in == "Cleo") return 2;
  if (in == "Troll") return 3;
  if (in == "Dracul") return 4;
  if (in == "Snowy") return 5;
  if (in == "Hexadecimal") return 6;
}
int differ(int a, int b, int c) {
  int diff = max(a, max(b, c));
  diff -= min(a, min(b, c));
  return diff;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    arr[conv(a)][conv(c)] = 1;
  }
  int ex[3];
  cin >> ex[0] >> ex[1] >> ex[2];
  sort(ex, ex + 3);
  int div[400][3], till = 0;
  int diff = ex[2];
  for (int i = 1; i < 6; i++) {
    for (int j = 1; j < 7 - i; j++) {
      int now = differ(ex[0] / i, ex[1] / j, ex[2] / (7 - i - j));
      if (now < diff) {
        till = 0;
        diff = now;
        div[till][0] = i;
        div[till][1] = j;
        div[till][2] = 7 - i - j;
        till++;
      } else if (now == diff) {
        div[till][0] = i;
        div[till][1] = j;
        div[till][2] = 7 - i - j;
        till++;
      }
    }
  }
  int ans = 0;
  vector<int> bs;
  for (int k = 0; k < till; k++) {
    bs.clear();
    for (int i = 0; i < div[k][0]; i++) bs.push_back(1);
    for (int i = 0; i < div[k][1]; i++) bs.push_back(2);
    for (int i = 0; i < div[k][2]; i++) bs.push_back(3);
    do {
      int tp = 0;
      for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
          if (arr[i][j] && bs[i] == bs[j]) tp++;
        }
      }
      ans = max(ans, tp);
    } while (next_permutation((bs).begin(), (bs).end()));
  }
  cout << diff << " " << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
}
