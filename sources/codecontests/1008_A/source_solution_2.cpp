#include <bits/stdc++.h>
using namespace std;
bool Vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    if (!Vowel(s[i]) && s[i] != 'n' && !Vowel(s[i + 1])) {
      cout << "NO" << endl;
      return 0;
    }
  cout << "YES" << endl;
  return 0;
}
