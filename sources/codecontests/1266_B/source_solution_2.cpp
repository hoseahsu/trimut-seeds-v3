#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long int number;
    cin >> number;
    if (number <= 14) {
      cout << "NO" << endl;
      continue;
    }
    number = number % 14;
    if (number >= 1 && number <= 6)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
