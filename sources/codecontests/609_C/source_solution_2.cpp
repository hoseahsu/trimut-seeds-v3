#include <bits/stdc++.h>
using namespace std;
long long int power(long long int first, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0) {
    long long int second = power(first, n / 2);
    return second * second;
  } else
    return first * power(first, n - 1);
}
int strTOint(string s) {
  stringstream ss;
  int first;
  ss << s;
  ss >> first;
  return first;
}
double geo_dist(int a, int b, int c, int d) {
  double dd = (double)(a - c) * (a - c) + (b - d) * (b - d);
  double r = sqrt(dd) + 1e-9;
  return r;
}
long long int bigmod(long long int a, long long int p, long long int m) {
  if (p == 0) return 1 % m;
  if (p % 2 == 0) {
    long long int second = bigmod(a, p / 2, m);
    return (second * second) % m;
  } else {
    return (a * bigmod(a, p - 1, m)) % m;
  }
}
long long int first, second, d, g;
void ext_gcd(long long int a, long long int b) {
  if (b == 0) {
    first = 1;
    second = 0;
    d = a;
    return;
  }
  ext_gcd(b, a % b);
  long long int x1 = second;
  long long int y1 = first - (a / b) * second;
  first = x1;
  second = y1;
}
long long int modInv(long long int a, long long int m) {
  ext_gcd(a, m);
  first %= m;
  if (first < 0) first += m;
  return first;
}
int fx[] = {0, 0, -1, 1, -1, 1, 1, -1};
int fy[] = {1, -1, 0, 0, 1, 1, -1, -1};
map<string, int> mp;
vector<pair<int, int> > adj[1000];
vector<int> v;
int ara[100000];
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &ara[i]);
    sum += ara[i];
  }
  int avg = sum / n;
  int rem = sum % n;
  int need[100001];
  sort(ara, ara + n);
  for (int i = 0; i < n; i++) {
    need[i] = avg;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (rem == 0) break;
    need[i]++;
    rem--;
  }
  int choto = 0;
  for (int i = 0; i < n; i++) {
    if (ara[i] > need[i]) choto += (ara[i] - need[i]);
  }
  printf("%d\n", choto);
  return 0;
}
