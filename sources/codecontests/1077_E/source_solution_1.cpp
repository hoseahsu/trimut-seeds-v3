#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return s; }
string to_string(char c) {
  string s = string(1, c);
  return s;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(vector<A> v) {
  string s = "(";
  int first = 1;
  for (A a : v) {
    if (!first) {
      s += ", ";
    }
    first = 0;
    s += to_string(a);
  }
  s += ")";
  return s;
}
template <typename A>
string to_string(set<A> v) {
  string s = "(";
  int first = 1;
  for (A a : v) {
    if (!first) {
      s += ", ";
    }
    first = 0;
    s += to_string(a);
  }
  s += ")";
  return s;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long long inf = (long long)1e18 + 5;
namespace SOLVE {
void main() {
  set<long long> A;
  map<long long, long long> freq;
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    A.insert(x);
    freq[x]++;
  }
  vector<long long> B;
  for (long long x : A) B.push_back(freq[x]);
  sort(B.rbegin(), B.rend());
  long long ans = 0;
  for (long long start = 1; start < 2e5 + 10; start++) {
    long long num = start;
    long long sum = 0;
    for (long long i = 0; i < B.size(); i++) {
      if (B[i] < num) break;
      sum += num;
      if (num % 2 == 1) break;
      num /= 2;
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
}
}  // namespace SOLVE
signed main() {
  long long t;
  t = 1;
  for (long long i = 0; i < t; i++) {
    SOLVE::main();
  }
  return 0;
}
