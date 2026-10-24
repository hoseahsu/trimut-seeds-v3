#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> m;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    int k;
    cin >> s >> k;
    if (m.find(s) == m.end() || m[s] < k) m[s] = k;
  }
  cout << m.size() << endl;
  int size = m.size();
  for (map<string, int>::iterator i = m.begin(); i != m.end(); i++) {
    double c = 0;
    for (map<string, int>::iterator j = m.begin(); j != m.end(); j++)
      if (i->second >= j->second) c++;
    if (c / size * 100 < 50)
      cout << i->first << " noob\n";
    else if (c / size * 100 >= 50 && c / size * 100 < 80)
      cout << i->first << " random\n";
    else if (c / size * 100 >= 80 && c / size * 100 < 90)
      cout << i->first << " average\n";
    else if (c / size * 100 >= 90 && c / size * 100 < 99)
      cout << i->first << " hardcore\n";
    else
      cout << i->first << " pro\n";
  }
  return 0;
}
