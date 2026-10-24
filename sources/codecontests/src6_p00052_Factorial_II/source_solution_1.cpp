#include <iostream>

using namespace std;

int main() {
  long long n;
  for (;;) {
    cin >> n;
    if (!n) return 0;
    long long r = 0, x = 1;
    for (int i = 0; i < 15; i++) {
      x *= 5;
      r += n / x;
    }
    cout << r << endl;
  }
}