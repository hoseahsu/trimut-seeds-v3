#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << "<" << p.first << "," << p.second << ">";
}
template <typename... T>
ostream& operator<<(ostream& os, const vector<T...>& c) {
  if (c.empty()) return os << "{ }";
  auto iter = c.cbegin();
  os << "{ " << *iter;
  while (++iter != c.cend()) os << ", " << *iter;
  return os << " }";
};
template <typename... T>
ostream& operator<<(ostream& os, const set<T...>& c) {
  if (c.empty()) return os << "{ }";
  auto iter = c.cbegin();
  os << "{ " << *iter;
  while (++iter != c.cend()) os << ", " << *iter;
  return os << " }";
};
template <typename... T>
ostream& operator<<(ostream& os, const map<T...>& c) {
  if (c.empty()) return os << "{ }";
  auto iter = c.cbegin();
  os << "{ " << *iter;
  while (++iter != c.cend()) os << ", " << *iter;
  return os << " }";
};
void dbg() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg(Head h, Tail... t) {
  cerr << " " << h;
  dbg(t...);
}
template <typename T>
T& minn(T& x, const T& y) {
  return x = min(x, y);
}
template <typename T>
T& maxx(T& x, const T& y) {
  return x = max(x, y);
}
constexpr const int mod = 1000000007;
constexpr int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
constexpr int sub(int a, int b) { return a < b ? mod + a - b : a - b; }
constexpr int mul(int a, int b) { return 1LL * a * b % mod; }
template <typename... T>
constexpr int add(int a, int b, T... c) {
  return add(add(a, b), c...);
};
template <typename... T>
constexpr int sub(int a, int b, T... c) {
  return sub(sub(a, b), c...);
};
template <typename... T>
constexpr int mul(int a, int b, T... c) {
  return mul(mul(a, b), c...);
};
constexpr int square(int a) { return mul(a, a); }
constexpr int fpow(int a, int b) {
  return b ? mul(b & 1 ? a : 1, square(fpow(a, b >> 1))) : 1;
}
struct trie {
  int son[2];
};
trie node[1 << 21];
int cnt = 1;
void insert(int i, int x, int d) {
  if (!~d) return;
  int j = x >> d & 1;
  if (!node[i].son[j]) node[i].son[j] = ++cnt;
  insert(node[i].son[j], x, d - 1);
}
int dfs(int i, int d) {
  if (!~d) return 0;
  if (node[i].son[0] && node[i].son[1])
    return 1 << d ^ min(dfs(node[i].son[0], d - 1), dfs(node[i].son[1], d - 1));
  return dfs(node[i].son[0] ^ node[i].son[1], d - 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    insert(1, a, 29);
  }
  cout << dfs(1, 29) << endl;
}
