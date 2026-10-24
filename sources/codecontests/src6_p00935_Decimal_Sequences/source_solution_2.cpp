#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    string s;
    for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      s += c;
    }
    int m = 0;
    char buff[10000];
    while (true) {
      sprintf(buff, "%d", m);
      string t(buff);
      if (s.find(t) == string::npos) {
        cout << t << endl;
        break;
      }
      ++m;
    }
  }
  return 0;
}