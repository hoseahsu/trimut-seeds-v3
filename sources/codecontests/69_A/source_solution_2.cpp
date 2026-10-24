#include <bits/stdc++.h>
using namespace std;
long long a, b, c, anss1 = 0, anss2 = 0, anss3 = 0, n;
string s;
bool flag[1000];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    anss1 += a;
    anss2 += b;
    anss3 += c;
  }
  if (!anss1 && !anss2 && !anss3) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
