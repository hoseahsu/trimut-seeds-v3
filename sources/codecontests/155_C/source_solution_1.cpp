#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
pair<char, char> v[15];
int main() {
  int ans = 0, l;
  string s;
  cin >> s;
  l = (int)(s.size());
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    cin >> v[i].first;
    cin >> v[i].second;
  }
  for (int i = 0; i < k; i++) {
    char a = v[i].first;
    char b = v[i].second;
    char tmp;
    int j = 0;
    while (j < l) {
      if (s[j] == a || s[j] == b) {
        int k = j;
        char c = s[j];
        int cnt = 0;
        while (j < l && (s[j] == a || s[j] == b)) {
          if (s[j] == c) cnt++;
          j++;
        }
        if (j - k != cnt) ans += min(cnt, j - k - cnt);
      } else
        j++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
