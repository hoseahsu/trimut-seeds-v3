#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool mmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool mmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;
int N;
long long A[MAXN], B[MAXN];
long long sum;
vector<long long> f(long long x) {
  vector<long long> v;
  for (int i = 2; 1LL * i * i <= x; i++) {
    if (x % i == 0) {
      v.push_back(i);
      if (1LL * i * i != x) v.push_back(x / i);
    }
  }
  return v;
}
long long solve(long long x) {
  for (int i = 0; i < (int)(N); ++i) B[i] = A[i];
  long long ret = 0;
  for (int i = 0; i < (int)(N - 1); ++i) {
    if (B[i] < 0) {
      B[i + 1] += B[i];
      ret += -B[i];
    } else if (B[i]) {
      long long r = B[i] % x;
      if (r * 2 <= x) {
        B[i + 1] += r;
        ret += r;
      } else {
        B[i + 1] -= x - r;
        ret += x - r;
      }
    }
  }
  assert(B[N - 1] % x == 0);
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < (int)(N); ++i) {
    cin >> A[i];
    sum += A[i];
  }
  if (sum == 1) do {
      cout << -1 << '\n';
      return 0;
    } while (0);
  auto factors = f(sum);
  factors.push_back(sum);
  long long ans = 1e18;
  for (long long fact : factors) {
    ans = min(ans, solve(fact));
  }
  cout << ans << endl;
  return 0;
}
