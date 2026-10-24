#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count = 0, count3 = 0, count2 = 0, count1 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U') {
      if (count2 > 0) {
        count2--;
      } else
        count++;
    } else if (s[i] == 'R') {
      if (count3 > 0) {
        count3--;
      } else
        count1++;
    } else if (s[i] == 'D') {
      if (count > 0) {
        count--;
      } else
        count2++;
    } else if (count1 > 0) {
      count1--;
    } else
      count3++;
  }
  if (abs(count + count2 + count3 + count1) % 2 == 0)
    cout << abs(count + count2 + count3 + count1) / 2 << endl;
  else
    cout << "-1" << endl;
}
