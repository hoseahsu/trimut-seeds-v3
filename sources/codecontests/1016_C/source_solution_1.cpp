#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
using namespace std;
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
long long histogram(long long arr[], long long n) {
  stack<int> s;
  int area = 0, i = 0;
  while (i < n) {
    if (s.empty() || arr[s.top()] <= arr[i])
      s.push(i++);
    else {
      int tp = s.top();
      s.pop();
      int xx = arr[tp] * (s.empty() ? i : i - s.top() - 1);
      area = max(area, xx);
    }
  }
  while (!s.empty()) {
    int tp = s.top();
    s.pop();
    int xx = arr[tp] * (s.empty() ? i : i - s.top() - 1);
    area = max(area, xx);
  }
  return area;
}
long long dp1[2][2000010], dp2[2][2000010], arr[2][2000010], kp[2][2000010];
char str[2000010];
int main() {
  long long n, m, k, a, b;
  long long sum = 0;
  string s, g;
  cin >> n;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  kp[0][0] = arr[0][0];
  for (int i = 1; i < n; i++) {
    kp[0][i] += kp[0][i - 1] + arr[0][i];
  }
  kp[1][0] = arr[1][0];
  for (int i = 1; i < n; i++) {
    kp[1][i] += kp[1][i - 1] + arr[1][i];
  }
  for (int i = 0; i < n; i++) {
    dp1[0][i] = arr[0][i] * i;
  }
  for (int i = n - 2; i >= 0; i--) {
    dp1[0][i] += dp1[0][i + 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    dp1[1][i] = arr[1][i] * ((2 * n) - (i + 1));
  }
  for (int i = n - 2; i >= 0; i--) {
    dp1[1][i] += dp1[1][i + 1];
  }
  for (int i = 0; i < n; i++) {
    dp2[1][i] = arr[1][i] * i;
  }
  for (int i = n - 2; i >= 0; i--) {
    dp2[1][i] += dp2[1][i + 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    dp2[0][i] = arr[0][i] * ((2 * n) - (i + 1));
  }
  for (int i = n - 2; i >= 0; i--) {
    dp2[0][i] += dp2[0][i + 1];
  }
  int now = 0;
  long long mx = dp1[0][0] + dp1[1][0];
  int flg = 0;
  for (int i = 0; i < n - 1; i++) {
    if (!flg) {
      sum += (now * arr[0][i]);
      now++;
      sum += (now * arr[1][i]);
      now++;
      long long ok = sum + (dp2[0][i + 1] + dp2[1][i + 1]) +
                     ((kp[1][n - 1] - kp[1][i] + kp[0][n - 1] - kp[0][i]) *
                      (now - (i + 1)));
      mx = max(mx, ok);
      flg = 1;
    } else {
      sum += (now * arr[1][i]);
      now++;
      sum += (now * arr[0][i]);
      now++;
      long long ok = sum + (dp1[0][i + 1] + dp1[1][i + 1]) +
                     ((kp[1][n - 1] - kp[1][i] + kp[0][n - 1] - kp[0][i]) *
                      (now - (i + 1)));
      mx = max(mx, ok);
      flg = 0;
    }
  }
  cout << mx << endl;
  return 0;
}
