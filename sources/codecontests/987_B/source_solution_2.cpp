#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
const long long LINF = 1e17;
const double pi = 3.1415926535897932;
const string endstr = "\n";
template <typename T>
T gcd(T a, T b) {
  return (a == 0) ? b : gcd(b % a, a);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
bool p_comp_fs(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first < p2.first;
};
bool p_comp_fg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first > p2.first;
};
bool p_comp_ss(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second < p2.second;
};
bool p_comp_sg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second > p2.second;
};
template <typename T>
vector<T> uniquen(vector<T> vec) {
  sort((vec).begin(), (vec).end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
inline long long popcnt(long long x) {
  return __builtin_popcountll((unsigned long long)x);
};
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x, y;
  cin >> x >> y;
  if (x == y || (x == 2 && y == 4) || (x == 4 && y == 2)) {
    cout << "=" << endstr;
    return 0;
  }
  double ylnx = (double)y * log((double)x);
  double xlny = (double)x * log((double)y);
  if (ylnx < xlny) {
    cout << "<" << endstr;
  } else {
    cout << ">" << endstr;
  }
  return 0;
}
