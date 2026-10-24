#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.X << ", " << pair.Y << ")";
}
const int N = 3e5 + 5;
int sus[N][2];
int deg[N];
set<pair<int, int> > bad;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }
map<pair<int, int>, int> degs;
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  int n, p;
  cin >> n >> p;
  ;
  for (int i = (1); i <= (n); ++i) {
    cin >> sus[i][0] >> sus[i][1];
    if (sus[i][0] > sus[i][1]) {
      swap(sus[i][0], sus[i][1]);
    }
    deg[sus[i][0]]++;
    deg[sus[i][1]]++;
  }
  vector<pair<int, int> > vec;
  for (int i = (1); i <= (n); ++i) {
    vec.push_back(make_pair(deg[i], i));
  }
  sort((vec).begin(), (vec).end(), cmp);
  int pos = vec.size() - 1;
  long long res = 0;
  for (int i = 0; i < vec.size(); i++) {
    while (vec[i].first + vec[pos].first < p && pos) {
      pos--;
    }
    res += max(0, pos - i);
    ;
    ;
  }
  for (int i = (1); i <= (n); ++i) {
    pair<int, int> para = make_pair(sus[i][0], sus[i][1]);
    if (degs[para] == 0) {
      degs[para] = deg[sus[i][0]] + deg[sus[i][1]];
    }
    degs[para]--;
    if (degs[para] == p - 1) {
      res--;
    }
  }
  cout << res << endl;
  return 0;
}
