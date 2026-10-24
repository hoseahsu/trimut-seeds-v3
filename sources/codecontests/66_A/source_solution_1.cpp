#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string b = "127", sh = "32767", in = "2147483647", l = "9223372036854775807";
  int n = s.size();
  if (n < 3) {
    cout << "byte";
    return 0;
  }
  if (n == 3) {
    for (int i = 0; i < 3; i++) {
      if (s[i] == b[i]) continue;
      if (s[i] > b[i]) {
        cout << "short";
        return 0;
      }
      if (s[i] < b[i]) {
        cout << "byte";
        return 0;
      }
    }
    cout << "byte";
    return 0;
  }
  if (n < 5) {
    cout << "short";
    return 0;
  }
  if (n == 5) {
    for (int i = 0; i < 5; i++) {
      if (s[i] == sh[i]) continue;
      if (s[i] > sh[i]) {
        cout << "int";
        return 0;
      }
      if (s[i] < sh[i]) {
        cout << "short";
        return 0;
      }
    }
    cout << "short";
    return 0;
  }
  if (n < 10) {
    cout << "int";
    return 0;
  }
  if (n == 10) {
    for (int i = 0; i < 10; i++) {
      if (s[i] == in[i]) continue;
      if (s[i] > in[i]) {
        cout << "long";
        return 0;
      }
      if (s[i] < in[i]) {
        cout << "int";
        return 0;
      }
    }
    cout << "int";
    return 0;
  }
  if (n < 19) {
    cout << "long";
    return 0;
  }
  if (n == 19) {
    for (int i = 0; i < 19; i++) {
      if (s[i] == l[i]) continue;
      if (s[i] > l[i]) {
        cout << "BigInteger";
        return 0;
      }
      if (s[i] < l[i]) {
        cout << "long";
        return 0;
      }
    }
    cout << "long";
    return 0;
  }
  cout << "BigInteger";
  return 0;
}
