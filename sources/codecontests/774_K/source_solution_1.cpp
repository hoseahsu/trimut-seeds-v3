#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int used[n];
  for (int i = 0; i < n; i++) {
    used[i] = 0;
  }
  string s;
  cin >> s;
  int i = 0;
  while (i < s.length()) {
    if (s[i] == 'e' && (i + 1 < n && s[i + 1] == 'e') &&
        ((i - 1 > -1 && s[i - 1] != 'e') || i - 1 <= -1) &&
        ((i + 2 < n && s[i + 2] != 'e') || i + 2 >= n)) {
      used[i] = 1;
      used[i + 1] = 1;
      i += 1;
    } else if (s[i] == 'o' && (i + 1 < n && s[i + 1] == 'o') &&
               ((i - 1 > -1 && s[i - 1] != 'o') || i - 1 <= -1) &&
               ((i + 2 < n && s[i + 2] != 'o') || i + 2 >= n)) {
      used[i] = 1;
      used[i + 1] = 1;
      i += 1;
    }
    i++;
  }
  int j = 1;
  while (j < s.length()) {
    if (used[j] == 1) {
      j++;
    } else {
      if (s[j] == s[j - 1] && (s[j] == 'i' || s[j] == 'y' || s[j] == 'u' ||
                               s[j] == 'o' || s[j] == 'e' || s[j] == 'a')) {
        used[j] = 2;
      }
      j++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (used[i] != 2) {
      cout << s[i];
    }
  }
  return 0;
}
