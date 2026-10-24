#include <bits/stdc++.h>
using namespace std;
int main() {
  int xx1 = INT_MAX, xx2 = -1, yy1 = INT_MAX, yy2 = -1;
  int x1, y1, x2, y2;
  int n, sum = 0;
  cin >> n;
  while (n--) {
    cin >> x1 >> y1 >> x2 >> y2;
    xx1 = min(xx1, x1);
    xx2 = max(xx2, x2);
    yy1 = min(yy1, y1);
    yy2 = max(yy2, y2);
    sum += (x2 - x1) * (y2 - y1);
  }
  if ((xx2 - xx1) == (yy2 - yy1) && (xx2 - xx1) * (yy2 - yy1) == sum)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
