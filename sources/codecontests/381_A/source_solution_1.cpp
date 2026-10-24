#include <bits/stdc++.h>
using namespace std;
int n;
int lista[10001];
int d1, d2;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> lista[i];
  int min = 1;
  int max = n;
  int vez = 0;
  for (int i = 1; i <= n; i++) {
    if (vez % 2 == 0) {
      if (lista[max] > lista[min]) {
        d1 += lista[max];
        max--;
      } else {
        d1 += lista[min];
        min++;
      }
      vez++;
    } else {
      if (lista[max] > lista[min]) {
        d2 += lista[max];
        max--;
      } else {
        d2 += lista[min];
        min++;
      }
      vez++;
    }
  }
  cout << d1 << " " << d2;
}
int main() { solve(); }
