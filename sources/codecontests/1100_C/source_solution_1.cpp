#include <bits/stdc++.h>
using namespace std;
int main(void) {
  double n, r;
  cin >> n >> r;
  double theta = 3.1415926535897 / n;
  printf("%.7f", sin(theta) * r / (1 - sin(theta)));
}
