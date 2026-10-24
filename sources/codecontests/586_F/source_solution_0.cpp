#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
const long long MOD = 1000000000 + 7;
const long long MAXN = 100000 + 100;
const long long MAGIC = 123123123;
const double PI = 4 * atan(1.);
const double EPS = 1E-7;
struct cmp_for_set {
  bool operator()(const int& a, const int& b) { return a > b; }
};
void time_elapsed() {
  cout << "\nTIME ELAPSED: " << (double)clock() / CLOCKS_PER_SEC << " sec\n";
}
template <typename T>
T gcd(T a, T b) {
  return ((!b) ? a : gcd(b, a % b));
}
template <typename T>
T gcd(T a, T b, T& x, T& y) {
  if (!a) {
    x = 0, y = 1;
    return b;
  }
  T x1, y1;
  T d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
template <typename T>
T lcm(T a, T b) {
  return (a / gcd(a, b)) * b;
}
template <typename T, typename M>
T neg_mod(T a, M mod) {
  return ((a % mod) + mod) % mod;
}
long long binpow(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
long long binpow_mod(long long x, long long p, long long m) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
struct state {
  long long mask;
  long long sum[3];
  state() {
    mask = 0;
    sum[0] = sum[1] = sum[2] = 0;
  }
};
bool operator<(const state& a, const state& b) {
  return (
      a.sum[0] < b.sum[0] || (a.sum[0] == b.sum[0] && a.sum[1] < b.sum[1]) ||
      (a.sum[0] == b.sum[0] && a.sum[1] == b.sum[1] && a.sum[2] < b.sum[2]));
}
char let[] = {'L', 'M', 'W'};
int main() {
  int n;
  cin >> n;
  vector<vector<long long>> vec1(n / 2, vector<long long>(3)),
      vec2(n - n / 2, vector<long long>(3));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i < n / 2) {
        scanf("%I64d", &vec1[i][j]);
      } else {
        scanf("%I64d", &vec2[i - n / 2][j]);
      }
    }
  }
  map<pair<long long, long long>, state> mem;
  vector<long long> pow3(20);
  pow3[0] = 1;
  for (int i = 1; i < 20; ++i) {
    pow3[i] = pow3[i - 1] * 3LL;
  }
  vector<long long> cmask(20);
  for (int mask = 0; mask < pow3[vec1.size()]; ++mask) {
    long long mm = mask;
    for (int j = 0; j < vec1.size(); ++j) {
      cmask[j] = mm % 3;
      mm /= 3;
    }
    state cur_state;
    for (int j = 0; j < vec1.size(); ++j) {
      for (int k = 0; k < 3; ++k) {
        cur_state.sum[k] += vec1[j][k];
      }
      cur_state.sum[cmask[j]] -= vec1[j][cmask[j]];
    }
    cur_state.mask = mask;
    pair<long long, long long> cur_delta =
        make_pair(cur_state.sum[1] - cur_state.sum[0],
                  cur_state.sum[2] - cur_state.sum[0]);
    if (!mem.count(cur_delta)) {
      mem[cur_delta] = cur_state;
    } else if (mem[cur_delta] < cur_state) {
      mem[cur_delta] = cur_state;
    }
  }
  pair<long long, long long> best;
  long long best_sum = -9999999999999999;
  for (int mask = 0; mask < pow3[vec2.size()]; ++mask) {
    long long mm = mask;
    for (int j = 0; j < vec2.size(); ++j) {
      cmask[j] = mm % 3;
      mm /= 3;
    }
    state cur_state;
    for (int j = 0; j < vec2.size(); ++j) {
      for (int k = 0; k < 3; ++k) {
        cur_state.sum[k] += vec2[j][k];
      }
      cur_state.sum[cmask[j]] -= vec2[j][cmask[j]];
    }
    cur_state.mask = mask;
    pair<long long, long long> cur_delta =
        make_pair(cur_state.sum[1] - cur_state.sum[0],
                  cur_state.sum[2] - cur_state.sum[0]);
    pair<long long, long long> need = cur_delta;
    need.first *= -1;
    need.second *= -1;
    if (mem.count(need)) {
      state ss = mem[need];
      if (cur_state.sum[0] + ss.sum[0] > best_sum) {
        best_sum = cur_state.sum[0] + ss.sum[0];
        best = make_pair(ss.mask, cur_state.mask);
      }
    }
  }
  if (best_sum == -9999999999999999) {
    puts("Impossible");
  } else {
    for (int j = 0; j < vec1.size(); ++j) {
      long long mm = best.first;
      for (int j = 0; j < vec1.size(); ++j) {
        cmask[j] = mm % 3;
        mm /= 3;
      }
      for (int k = 0; k < 3; ++k) {
        if (cmask[j] != k) {
          printf("%c", let[k]);
        }
      }
      printf("\n");
    }
    for (int j = 0; j < vec2.size(); ++j) {
      long long mm = best.second;
      for (int j = 0; j < vec2.size(); ++j) {
        cmask[j] = mm % 3;
        mm /= 3;
      }
      for (int k = 0; k < 3; ++k) {
        if (cmask[j] != k) {
          printf("%c", let[k]);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
