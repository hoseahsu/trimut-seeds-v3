#include <bits/stdc++.h>
using namespace std;
int main() {
  string X;
  cin >> X;
  int size = X.length();
  bool con = true;
  int A[size], higher = 0;
  for (int i = 0; i < size; i++) {
    A[i] = X[i] - '0';
    if (A[i] > higher) higher = A[i];
  }
  cout << higher << endl;
  while (con) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
      if (A[i] > 0) {
        temp = temp * 10 + 1;
        A[i]--;
      } else
        temp = temp * 10;
    }
    if (temp == 0)
      con = false;
    else
      cout << temp << " ";
  }
  return 0;
}
