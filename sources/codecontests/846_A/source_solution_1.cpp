#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2) {
  return p1.first != p2.first ? p1.first < p2.first : p1.second < p2.second;
}
long long dist(pair<long long, long long> p1, pair<long long, long long> p2) {
  return (p1.first - p2.first) * (p1.first - p2.first) +
         (p2.second - p1.second) * (p2.second - p1.second);
}
long long fast_exp(long long base, long long n, long long m) {
  if (n == 0) return 1;
  long long t = fast_exp(base, n / 2, m);
  if (n % 2 == 0)
    return (t * t) % m;
  else
    return (((t * t) % m) * base) % m;
}
int count_bits(long long mask) {
  int ans = 0;
  for (int i = 0; i < 64; i++)
    if (((((i & (1 << mask)) >> mask) > 0 ? 1 : 0))) ans++;
  return ans;
}
int first_bit(long long mask) {
  int i = 0;
  while (i < 64)
    if (((((i++ & (1 << mask)) >> mask) > 0 ? 1 : 0))) return i - 1;
  return -1;
}
bool ch(string s) {
  for (int i = 0; i < s.length() / 2; i++)
    if (s[i] != s[s.length() - i - 1]) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, ans_z = 0, ans_o = 0, ans = 0;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++)
    cin >> array[i], array[i] == 0 ? ans_z++ : ans_o++;
  for (int i = 0; i < n; i++) {
    int zeros = 0, ones = 0;
    for (int z = 0; z < i; z++) zeros += (array[z] == 0);
    for (int o = i + 1; o < n; o++) ones += (array[o] == 1);
    ans = std::max(ans, zeros + ones + 1);
  }
  cout << std::max(ans_o, std::max(ans_z, ans)) << endl;
  return 0;
}
