#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
const long long int INF = 1e18 + 7;
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long int a, long long int b) { return (a / gcd(a, b)) * b; }
long long int power(long long int x, long long int y, long long int INF) {
  long long int res = 1;
  x = x % INF;
  while (y > 0) {
    if (y & 1) res = (res * x) % INF;
    y = y >> 1;
    x = (x * x) % INF;
  }
  return res % INF;
}
void WetPitch() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int right[n];
  long long int left[n];
  right[0] = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] > v[i - 1]) {
      right[i] = right[i - 1] + 1;
    } else {
      right[i] = 0;
    }
  }
  left[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] < v[i + 1]) {
      left[i] = left[i + 1] + 1;
    } else {
      left[i] = 0;
    }
  }
  long long int i = 0;
  long long int j = n - 1;
  string ans = "";
  long long int cnt = 0;
  long long int prev = -1;
  while (i <= j) {
    if (v[i] > prev && v[j] > prev) {
      if (v[i] > v[j]) {
        prev = v[j];
        cnt++;
        ans += 'R';
        j--;
      } else if (v[i] < v[j]) {
        prev = v[i];
        cnt++;
        ans += 'L';
        i++;
      } else {
        long long int x = 1, y = 1;
        for (int k = i; k < j; k++) {
          if (v[k] < v[k + 1]) {
            x++;
          } else {
            break;
          }
        }
        for (int k = j; k > i; k--) {
          if (v[k] < v[k - 1]) {
            y++;
          } else {
            break;
          }
        }
        if (x > y) {
          for (int k = 1; k <= x; k++) {
            ans += 'L';
            cnt++;
          }
          break;
        } else {
          for (int k = 1; k <= y; k++) {
            ans += 'R';
            cnt++;
          }
          break;
        }
      }
    } else if (v[i] > prev) {
      prev = v[i];
      cnt++;
      ans += 'L';
      i++;
    } else if (v[j] > prev) {
      prev = v[j];
      cnt++;
      ans += 'R';
      j--;
    } else {
      break;
    }
  }
  cout << cnt << '\n';
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int tst;
  tst = 1;
  while (tst--) {
    WetPitch();
  }
  return 0;
}
