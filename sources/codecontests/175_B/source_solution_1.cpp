#include <bits/stdc++.h>
using namespace std;
int dir1[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, 2, -2, 1, -1, -2, -2, -1};
int dir2[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int dir3[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1};
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
bool isPrime(int x) {
  if (x == 1)
    return false;
  else if (x == 2)
    return true;
  for (int i = 2; i <= sqrt(x * 1.0); ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int sqr(int x) { return x * x; }
struct Node {
  string name;
  int score;
  string level;
} x[1200];
bool cmp(Node a, Node b) { return a.name < b.name; }
int main() {
  int n;
  set<string> st;
  while (~scanf("%d", &n)) {
    string s;
    int m;
    int ans = 0;
    st.clear();
    for (int i = 0; i < n; ++i) {
      cin >> s >> m;
      if (st.find(s) == st.end()) {
        st.insert(s);
        x[ans].name = s;
        x[ans].score = m;
        ans++;
      } else {
        for (int j = 0; j < ans; ++j) {
          if (x[j].name == s) {
            x[j].score = max(x[j].score, m);
            break;
          }
        }
      }
    }
    for (int i = 0; i < ans; ++i) {
      int cnt = 0;
      for (int j = 0; j < ans; ++j) {
        if (x[i].score >= x[j].score) cnt++;
      }
      if (100 * cnt < 50 * ans)
        x[i].level = "noob";
      else if (100 * cnt < 80 * ans)
        x[i].level = "random";
      else if (100 * cnt < 90 * ans)
        x[i].level = "average";
      else if (100 * cnt < 99 * ans)
        x[i].level = "hardcore";
      else
        x[i].level = "pro";
    }
    sort(x, x + ans, cmp);
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) {
      cout << x[i].name << " " << x[i].level << endl;
    }
  }
  return 0;
}
