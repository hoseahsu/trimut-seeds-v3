#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000009;
const long long MAX_N = 100001;
int count(int r, int h) {
  float baseLen = ((sqrt(3.0) * 0.5) * r);
  int num;
  if (h > baseLen) {
    num = 2 * ((h - baseLen) / r) + 3;
  } else if (h >= r * 0.5) {
    num = 2;
  } else {
    num = 1;
  }
  return num;
}
int main(int argc, char** argv) {
  int r, h;
  int num;
  cin >> r >> h;
  num = count(r, h);
  cout << num << endl;
  return 0;
}
