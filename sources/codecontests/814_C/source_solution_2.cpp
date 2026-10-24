#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool you[26];
int need[26][1550];
int q;
int main() {
  scanf("%d", &n);
  cin >> s;
  for (int i = 0; i < n; i++) {
    you[s[i] - 'a'] = 1;
    int ndd = 0;
    for (int j = i; j < n; j++) {
      if (s[j] != s[i]) ndd++;
      need[s[i] - 'a'][ndd] = max(need[s[i] - 'a'][ndd], j - i + 1);
    }
    for (int j = i - 1; j >= 0; j--) {
      if (s[j] != s[i]) ndd++;
      need[s[i] - 'a'][ndd] = max(need[s[i] - 'a'][ndd], n - j);
    }
  }
  for (int i = 0; i < 26; i++)
    for (int j = 1; j < 1550; j++) need[i][j] = max(need[i][j - 1], need[i][j]);
  scanf("%d", &q);
  int a;
  char b;
  while (q--) {
    scanf("%d %c", &a, &b);
    if (!you[b - 'a'])
      printf("%d\n", a);
    else
      printf("%d\n", need[b - 'a'][a]);
  }
  return 0;
}
