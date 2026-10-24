#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int day, name, rem, r;
  cin >> day >> name;
  int dy[day], pg[day];
  for (int i = 0; i < day; i++) {
    cin >> dy[i];
  }
  for (int i = 0; i < day; i++) {
    rem = dy[i] % name;
    r = dy[i] / name;
    if (i + 1 != day) {
      dy[i + 1] += rem;
    }
    pg[i] = r;
  }
  for (int i = 0; i < day; i++) {
    cout << pg[i] << " ";
  }
}
