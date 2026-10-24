#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie();
  long long n;
  cin >> n;
  long long a[n];
  map<long long, long long> m;
  vector<long long> x, y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  for (auto i = m.begin(); i != m.end(); i++) {
    if (i->second > 2) {
      cout << "No"
           << "\n";
      return 0;
    }
  }
  cout << "Yes"
       << "\n";
  for (auto j = m.begin(); j != m.end(); j++) {
    if (j->second == 2) {
      x.push_back(j->first);
      j->second--;
    }
    if (j->second == 1) {
      y.push_back(j->first);
      j->second--;
    }
  }
  cout << x.size() << "\n";
  for (int i = 0; i < x.size(); i++) cout << x[i] << " ";
  cout << "\n";
  cout << y.size() << "\n";
  for (int i = y.size(); i > 0; i--) cout << y[i - 1] << " ";
}
