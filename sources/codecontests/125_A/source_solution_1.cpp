#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int Foot = N / 36, Rest = N % 36,
      Inch = (Rest % 3 == 2) ? (Rest / 3 + 1) : (Rest / 3);
  if (Inch == 12) {
    Foot++;
    Inch = 0;
  }
  cout << Foot << ' ' << Inch << endl;
  return 0;
}
