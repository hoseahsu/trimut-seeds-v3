#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ii = pair<int, int>;
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
  vector<int> ord(size);
  for (int i = 0; i < size; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), compare);
  return ord;
}
template <typename T>
bool MinPlace(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <class TH>
void _dbg(const char* name, TH val) {
  clog << name << ": " << val << endl;
}
template <class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
  while (*names != ',') clog << *names++;
  clog << ": " << curr_val << ", ";
  _dbg(names + 1, vals...);
}
const int MAXN = 1e5 + 100;
int a[MAXN];
vector<ii> ans;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int h_free = 1;
  vector<ii> req[4];
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    if (a[i] == 1) {
      if (req[2].empty() && req[3].empty()) {
        ans.emplace_back(i, h_free);
        h_free++;
      } else {
        ii cima;
        if (req[2].empty()) {
          cima = req[3].back();
          req[3].pop_back();
        } else {
          cima = req[2].back();
          req[2].pop_back();
        }
        ans.emplace_back(i, cima.second);
        if (cima.first == 3) {
          ans.emplace_back(i, h_free);
          h_free++;
        }
      }
    } else {
      if (!req[3].empty()) {
        auto cima = req[3].back();
        req[3].pop_back();
        ans.emplace_back(i, cima.second);
      }
      ans.emplace_back(i, h_free);
      req[a[i]].emplace_back(a[i], h_free);
      h_free++;
    }
  }
  if (!req[2].empty() || !req[3].empty()) {
    cout << -1 << '\n';
  } else {
    cout << ans.size() << '\n';
    for (auto el : ans) cout << el.second << " " << el.first << '\n';
  }
  return 0;
}
