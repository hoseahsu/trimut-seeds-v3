#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  deque<int> dQ;
  for (int i{0}; i < n; ++i) {
    int a;
    cin >> a;
    dQ.push_back(a);
  }
  int a{0}, b{0};
  while (!dQ.empty()) {
    if (dQ.front() > dQ.back()) {
      a += dQ.front();
      dQ.pop_front();
    } else {
      a += dQ.back();
      dQ.pop_back();
    }
    if (dQ.empty()) break;
    if (dQ.front() > dQ.back()) {
      b += dQ.front();
      dQ.pop_front();
    } else {
      b += dQ.back();
      dQ.pop_back();
    }
  }
  cout << a << " " << b;
}
