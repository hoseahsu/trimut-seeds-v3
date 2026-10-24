#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  string p;
  cin >> str;
  int len = str.length();
  for (int i = 0; i < len; i += 2)
    for (int j = 0; j < len; j += 2)
      if (str[i] < str[j]) {
        swap(str[i], str[j]);
      }
  cout << str;
  return 0;
}
