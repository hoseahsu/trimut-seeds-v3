#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << "[";
  for (auto k : v) out << k << " ";
  out << "]"
      << "\n";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> s) {
  out << "{";
  for (auto k : s) out << k << " ";
  out << "}"
      << "\n";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U> p) {
  out << "[ " << p.first << " , " << p.second << " ] ";
  return out;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
vector<vector<int> > res;
int n;
void Ejecutar(vector<int> par, vector<int>& d) {
  vector<vector<int> > pars;
  vector<int> loc;
  int p = 0;
  for (auto k : par) {
    for (int j = 0; j < int(k); j++) {
      loc.push_back(d[p]);
      p++;
    }
    pars.push_back(loc);
    loc.resize(0);
  }
  reverse(pars.begin(), pars.end());
  vector<int> ld;
  for (auto k : pars)
    for (auto j : k) ld.push_back(j);
  d = ld;
}
void Paso(vector<int>& d, int i) {
  if (d[0] == 1) {
    int p = 0;
    while (d[p] != i) p++;
    if (p + 1 != i) {
      vector<int> par;
      for (int j = 0; j < int(i - 1); j++) par.push_back(1);
      par.push_back(p - i + 2);
      if (n - p - 1) par.push_back(n - p - 1);
      if (par.size() > 1) res.push_back(par);
      Ejecutar(par, d);
      return;
    }
  } else {
    int p = 0;
    while (d[n - p - 1] != i) p++;
    if (p + 1 != i) {
      vector<int> par;
      for (int j = 0; j < int(i - 1); j++) par.push_back(1);
      par.push_back(p - i + 2);
      if (n - p - 1) par.push_back(n - p - 1);
      reverse(par.begin(), par.end());
      if (par.size() > 1) res.push_back(par);
      Ejecutar(par, d);
      return;
    }
  }
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < int(n); i++) cin >> d[i];
  for (int i = 0; i < int(n); i++) {
    if (d[i] == 1) {
      if (i != 0 && i != n - 1) {
        vector<int> p = {i, n - i};
        if (p.size() > 1) res.push_back(p);
        Ejecutar(p, d);
      }
      break;
    }
  }
  for (int i = int(2); i < int(n); i++) {
    Paso(d, i);
  }
  if (d[0] == n) {
    vector<int> r(n);
    for (int i = 0; i < int(n); i++) r[i] = 1;
    if (r.size() > 1) res.push_back(r);
    Ejecutar(r, d);
  }
  cout << res.size() << "\n";
  for (auto r : res) {
    cout << r.size() << " ";
    for (auto k : r) cout << k << " ";
    cout << "\n";
  }
  return 0;
}
