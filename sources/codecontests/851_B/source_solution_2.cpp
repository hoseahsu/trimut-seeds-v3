#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
double slope(long long int x1, long long int y1, long long int x2,
             long long int y2) {
  return (double)((double)(y2 - y1) / (x2 - x1));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  long long int dab = power((bx - ax), 2) + power((by - ay), 2);
  long long int dbc = power((cx - bx), 2) + power((cy - by), 2);
  if (dab != dbc) {
    cout << "No\n";
  } else if (slope(ax, ay, bx, by) == slope(bx, by, cx, cy)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  return 0;
}
