#include <bits/stdc++.h>
using namespace std;
int vis[13], ans;
int dig[2][22];
long long l, r;
int tv[13];
bool dfs2(int now, int ulim, int dlim) {
  if (now == 0) {
    return 1;
  }
  if (ulim && dlim) {
    if (dig[0][now] == dig[1][now]) {
      if (tv[dig[0][now]]) {
        --tv[dig[0][now]];
        if (dfs2(now - 1, ulim, dlim)) {
          return 1;
        }
        ++tv[dig[1][now]];
      }
    } else {
      for (int i = dig[0][now] + 1; i < dig[1][now]; ++i) {
        if (tv[i]) {
          return 1;
        }
      }
      if (tv[dig[0][now]]) {
        --tv[dig[0][now]];
        if (dfs2(now - 1, 0, dlim)) {
          return 1;
        }
        ++tv[dig[0][now]];
      }
      if (tv[dig[1][now]]) {
        --tv[dig[1][now]];
        if (dfs2(now - 1, ulim, 0)) {
          return 1;
        }
        ++tv[dig[1][now]];
      }
    }
  } else if (!ulim && !dlim) {
    return 1;
  } else if (ulim && !dlim) {
    for (int i = 0; i < dig[1][now]; ++i) {
      if (tv[i]) {
        return 1;
      }
    }
    if (tv[dig[1][now]]) {
      --tv[dig[1][now]];
      if (dfs2(now - 1, ulim, 0)) {
        return 1;
      }
      ++tv[dig[1][now]];
    }
  } else if (!ulim && dlim) {
    for (int i = dig[0][now] + 1; i < 10; ++i) {
      if (tv[i]) {
        return 1;
      }
    }
    if (tv[dig[0][now]]) {
      --tv[dig[0][now]];
      if (dfs2(now - 1, 0, dlim)) {
        return 1;
      }
      ++tv[dig[0][now]];
    }
  }
  return 0;
}
bool check(int *v) {
  for (int i = 0; i < 10; ++i) {
    tv[i] = v[i];
  }
  return dfs2(18, 1, 1);
}
void dfs(int now, int left) {
  if (now == 9) {
    vis[9] = left;
    if (check(vis)) {
      ++ans;
    }
    return;
  }
  for (int i = 0; i <= left; ++i) {
    vis[now] = left - i;
    dfs(now + 1, i);
  }
}
int main() {
  cin >> l >> r;
  int flag = 0;
  if (r == 1000000000000000000ll) {
    if (l == r) {
      puts("1");
      return 0;
    }
    --r;
    flag = 1;
  }
  for (int i = 1; i <= 18; ++i) {
    dig[0][i] = l % 10;
    dig[1][i] = r % 10;
    l /= 10;
    r /= 10;
  }
  dfs(0, 18);
  if (flag) {
    memset(vis, 0, sizeof vis);
    vis[0] = 17;
    vis[1] = 1;
    if (!check(vis)) {
      ++ans;
    }
  }
  cout << ans << endl;
}
