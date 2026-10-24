#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n, x, y;
  cin >> n >> x >> y;
  if ((ceil(y * n / 100.0) - x) < 0)
    cout << 0 << endl;
  else
    cout << ceil(y * n / 100.0) - x << endl;
  return 0;
}
