#include <bits/stdc++.h>
using namespace std;
int n, arreglo[100005], arreglo2[100005], ones = 0, ones2 = 0, zeros = 0,
                                          zeros2 = 0, cont = 0;
int main() {
  cin >> n;
  for (int x = 1; x <= n; x++) {
    cin >> arreglo[x] >> arreglo2[x];
    if (arreglo[x] == 0) {
      zeros++;
    }
    if (arreglo[x] == 1) {
      ones++;
    }
    if (arreglo2[x] == 0) {
      zeros2++;
    }
    if (arreglo2[x] == 1) {
      ones2++;
    }
  }
  if (zeros < ones) {
    cont = cont + (n - ones);
  } else {
    cont = cont + (n - zeros);
  }
  if (zeros2 < ones2) {
    cont = cont + (n - ones2);
  } else {
    cont = cont + (n - zeros2);
  }
  cout << cont;
}
