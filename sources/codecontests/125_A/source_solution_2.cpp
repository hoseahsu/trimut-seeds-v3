#include <bits/stdc++.h>
using namespace std;
int main() {
  float n;
  cin >> n;
  float f, i;
  f = (int)(n / 36);
  i = (n - f * 36) / 3;
  if (i - (int)i != 0 && i - (int)i >= 0.5) i = (int)i + 1;
  if ((int)i % 12 == 0) {
    f = f + i / 12;
    i = 0;
  }
  cout << (int)f << " " << (int)i << endl;
  return 0;
}
