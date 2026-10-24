#include <bits/stdc++.h>
using namespace std;
const int BASE = 1000000007, MOD = 1000000009, N = 100001;
int arr[N];
long long val[N], P[N], rev[N];
map<int, vector<int> > M;
vector<pair<int, int> > vet;
long long power(int a, int b) {
  if (!b) return 1;
  long long p = power(a, b / 2);
  p = p * p % MOD;
  if (b % 2) p = p * a % MOD;
  return p;
}
long long inv(int x) { return power(x, MOD - 2); }
long long Hash(int from, int to) {
  return (val[to] - val[from - 1] + MOD) % MOD * rev[from] % MOD;
}
int main() {
  int n;
  scanf("%d", &n);
  P[0] = rev[0] = 1;
  P[1] = BASE;
  rev[1] = inv(BASE);
  for (int i = 2; i <= n; i++) {
    P[i] = P[i - 1] * P[1] % MOD;
    rev[i] = rev[i - 1] * rev[1] % MOD;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    arr[i]++;
    val[i] = (val[i - 1] + P[i] * arr[i]) % MOD;
    M[arr[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    for (int j : M[arr[i]])
      if (j > i) {
        int d = j - i;
        if (j + d - 1 <= n and Hash(i, i + d - 1) == Hash(j, j + d - 1))
          vet.push_back({d, i});
      }
  sort(vet.begin(), vet.end());
  int from = 1;
  for (auto i : vet) {
    if (i.second < from) continue;
    from = i.first + i.second;
  }
  printf("%d\n", n - from + 1);
  for (int i = from; i <= n; i++) printf("%d ", arr[i] - 1);
  return 0;
}
