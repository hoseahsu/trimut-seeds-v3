#include <bits/stdc++.h>
using namespace std;
int conversion(string p) {
  int o;
  o = atoi(p.c_str());
  return o;
}
string toString(int h) {
  stringstream ss;
  ss << h;
  return ss.str();
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
long long toi(string p) {
  long long x;
  istringstream in(p);
  in >> x;
  return x;
}
long long square(long long n) { return n * n; }
long long fastexp(long base, long power) {
  if (power == 0)
    return 1;
  else if (power % 2 == 0)
    return square(fastexp(base, power / 2));
  else
    return base * (fastexp(base, power - 1));
}
bool is_prime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int logba(int a, int b) { return log(a) / log(b); }
long long sum(long long x) { return ((x) * (x - 1)) / 2; }
int main() {
  long long n, x, y, res = 0;
  cin >> n;
  map<long long, long long> M, N;
  map<pair<long long, long long>, long long> R;
  set<pair<long long, long long> > S;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    M[x]++;
    N[y]++;
    S.insert(make_pair(x, y));
    R[make_pair(x, y)]++;
  }
  if (S.size() == 1) {
    cout << ((n) * (n - 1)) / 2 << endl;
    return 0;
  }
  for (map<long long, long long>::iterator it = M.begin(); it != M.end();
       it++) {
    res += sum(it->second);
  }
  for (map<long long, long long>::iterator it = N.begin(); it != N.end();
       it++) {
    res += sum(it->second);
  }
  for (map<pair<long long, long long>, long long>::iterator it = R.begin();
       it != R.end(); it++) {
    res -= sum(it->second);
  }
  cout << res << endl;
}
