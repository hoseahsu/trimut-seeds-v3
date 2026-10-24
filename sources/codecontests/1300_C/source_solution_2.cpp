#include <bits/stdc++.h>
using namespace std;
const bool DEBUG = false;
template <class T>
void print1D(T v) {
  if (DEBUG) {
    for (auto e : v) cout << e << " ";
    cout << endl;
  }
}
template <class T>
void print1D(T v, int min_incl, int max_incl) {
  if (DEBUG) {
    for (int i = min_incl; i <= max_incl; i++) cout << v[i] << " ";
    cout << endl;
  }
}
template <class T>
void print2D(T v) {
  if (DEBUG)
    for (auto a : v) print1D(a);
}
template <class T>
void print2D(T v, int min_incl, int max_incl, bool square) {
  if (DEBUG) {
    for (int i = min_incl; i <= max_incl; i++) {
      if (square)
        print1D(v[i], min_incl, max_incl);
      else
        print1D(v[i]);
    }
  }
}
template <class T>
void printPair(T p) {
  if (DEBUG) cout << "(" << p.first << ", " << p.second << ")" << endl;
}
vector<bool> decToBinary(int n) {
  vector<bool> binaryNum(32);
  int i = 0;
  while (n > 0) {
    binaryNum[32 - i - 1] = n % 2;
    n = n / 2;
    i++;
  }
  return binaryNum;
}
int main() {
  int n = 0;
  cin >> n;
  vector<vector<bool> > a(n);
  vector<int> orig(n);
  for (int i = 0; i < n; i++) {
    int in = 0;
    cin >> in;
    orig[i] = in;
    a[i] = decToBinary(in);
  }
  print2D(a);
  vector<int> digits_kept(32, -1);
  for (int j = 0; j < 32; j++) {
    for (int i = 0; i < n; i++) {
      if (a[i][j] && digits_kept[j] == -1) {
        digits_kept[j] = i;
      } else if (a[i][j] && digits_kept[j] != -1) {
        digits_kept[j] = -2;
      }
    }
  }
  print1D(digits_kept);
  vector<bool> used(n, false);
  vector<int> order;
  for (int i : digits_kept) {
    if (i >= 0 && !used[i]) {
      order.push_back(i);
      used[i] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      order.push_back(i);
    }
  }
  for (int i : order) {
    cout << orig[i] << " ";
  }
  cout << endl;
}
