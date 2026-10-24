#include <bits/stdc++.h>
using namespace std;
template <class FR>
inline FR max(FR& a, const FR& b) {
  return (a > b) ? a : b;
}
template <class FR>
inline FR min(FR& a, const FR& b) {
  return (a > b) ? b : a;
}
const int MAXN = (int)1e6 + 10;
const int MOD = (int)1e9 + 7;
const int INF = 998244353;
int grid[3000][3000];
int hor[3000][3000];
int vert[3000][3000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  struct Char {
    int i, j;
    char ch;
  };
  for (int i = 0; i < 1111; ++i) {
    for (int j = 0; j < 1111; ++j) {
      grid[i][j] = 1;
    }
  }
  vector<Char> sight;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; ++j) {
      if (s[j - 1] >= 'A' && s[j - 1] <= 'Z') {
        sight.push_back({i, j, s[j - 1]});
      }
      if (s[j - 1] != '#') {
        grid[i][j] = 0;
      }
    }
  }
  vector<pair<char, int>> instruction;
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    char dir;
    int len;
    cin >> dir >> len;
    instruction.push_back({dir, len});
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      hor[i][j] += hor[i][j - 1] + grid[i][j];
    }
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      vert[i][j] += vert[i - 1][j] + grid[i][j];
    }
  }
  string ans;
  for (auto [i, j, ch] : sight) {
    int fl = 0;
    for (auto [dir, len] : instruction) {
      if (dir == 'N') {
        if (i - len < 0) {
          fl = 1;
          break;
        }
        if (vert[i][j] - vert[i - len][j] == 0 && grid[i - len][j] == 0) {
          i -= len;
        } else {
          fl = 1;
          break;
        }
      }
      if (dir == 'S') {
        if (i + len > n) {
          fl = 1;
          break;
        }
        if (vert[i][j] - vert[i + len][j] == 0 && grid[i + len][j] == 0) {
          i += len;
        } else {
          fl = 1;
          break;
        }
      }
      if (dir == 'E') {
        if (j + len > m) {
          fl = 1;
          break;
        }
        if (hor[i][j] - hor[i][j + len] == 0 && grid[i][j + len] == 0) {
          j += len;
        } else {
          fl = 1;
          break;
        }
      }
      if (dir == 'W') {
        if (j - len < 0) {
          fl = 1;
          break;
        }
        if (hor[i][j] - hor[i][j - len] == 0 && grid[i][j - len] == 0) {
          j -= len;
        } else {
          fl = 1;
          break;
        }
      }
    }
    if (!fl) {
      ans += ch;
    }
  }
  if (ans.empty()) {
    cout << "no solution\n";
  } else {
    sort(ans.begin(), ans.end());
    cout << ans << '\n';
  }
  return 0;
}
