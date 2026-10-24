#include <bits/stdc++.h>
using namespace std;
bool mark[10000000 + 5];
int cnt[10000000 + 5], max_prime;
vector<int> prime;
void seive() {
  memset(mark, true, sizeof mark);
  for (int i = 2; i * i <= 10000000; i++) {
    for (int j = i + i; j <= 10000000; j += i) {
      mark[j] = false;
    }
  }
  for (int i = 2; i <= 10000000; i++) {
    if (mark[i]) prime.push_back(i);
  }
}
void fact(int n) {
  for (int i = 0; (i < prime.size() && prime[i] * prime[i] <= n); i++) {
    int d = prime[i];
    if (n % d == 0) {
      cnt[d]++;
      max_prime = max(max_prime, d);
      while (n % d == 0) n /= d;
    }
    if (n == 1) break;
  }
  if (n > 1) {
    cnt[n]++;
    max_prime = max(max_prime, n);
  }
}
int main() {
  seive();
  int n, a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    fact(a);
  }
  for (int i = 1; i <= max_prime; i++) cnt[i] += cnt[i - 1];
  int qq, l, r;
  scanf("%d", &qq);
  while (qq--) {
    scanf("%d %d", &l, &r);
    r = min(r, max_prime);
    l = min(l, max_prime + 1);
    printf("%d\n", cnt[r] - cnt[l - 1]);
  }
  return 0;
}
