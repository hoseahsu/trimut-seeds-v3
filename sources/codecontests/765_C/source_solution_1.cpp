#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, a, b, num1, num2, s1, s2;
  while (cin >> k >> a >> b) {
    num1 = a / k;
    num2 = b / k;
    s1 = a % k;
    s2 = b % k;
    if (num1 + num2 == 0) {
      cout << "-1" << endl;
    } else if (num1 == 0 && s2 != 0) {
      cout << "-1" << endl;
    } else if (num2 == 0 && s1 != 0) {
      cout << "-1" << endl;
    } else {
      cout << num1 + num2 << endl;
    }
  }
  return 0;
}
