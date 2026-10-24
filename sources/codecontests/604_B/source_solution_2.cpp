#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& s, vector<T>& v) {
  s << '{';
  for (int i = 0; i < v.size(); ++i) s << (i ? "," : "") << v[i];
  return s << '}';
}
template <typename S, typename T>
ostream& operator<<(ostream& s, pair<S, T>& p) {
  return s << "(" << p.first << "," << p.second << ")";
}
vector<int> bells;
int main() {
  int N, B;
  cin >> N >> B;
  if (B > N) B = N;
  for (int i = 0; i < (N); ++i) {
    int t;
    cin >> t;
    bells.push_back(t);
  }
  int size2 = N - B;
  int size1 = B - size2;
  assert(size1 + size2 == B);
  assert(size1 + 2 * size2 == N);
  int m = 0;
  for (int i = 0; i < (size2); ++i) {
    int s = 0;
    s += bells[i];
    s += bells[size2 * 2 - i - 1];
    m = max(m, s);
  }
  int ix = size2 * 2;
  for (int i = 0; i < (size1); ++i) {
    m = max(m, bells[ix]);
    ix++;
  }
  cout << m << endl;
}
