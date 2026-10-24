#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &a) {
  T x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ '0');
    ch = getchar();
  }
  a = f ? x : -x;
}
char s[1000010], t[1000010];
int q, opt, ls, lt, l, r;
bitset<100010> n[26];
bitset<100010> ans;
signed main() {
  scanf("%s", s);
  read(q);
  ls = strlen(s);
  for (int i = 0; i < ls; i++) {
    n[s[i] - 'a'][i] = 1;
  }
  while (q--) {
    read(opt);
    if (opt == 1) {
      int pos;
      read(pos);
      pos--;
      char ch = getchar();
      n[s[pos] - 'a'][pos] = 0;
      s[pos] = ch;
      n[s[pos] - 'a'][pos] = 1;
    } else {
      read(l), read(r);
      scanf("%s", t);
      l--;
      lt = strlen(t);
      ans.set();
      for (int i = 0; i < lt; i++) {
        ans &= (n[t[i] - 'a'] << lt - i - 1);
      }
      printf("%d\n",
             max(0, int((ans >> l + lt - 1).count() - (ans >> r).count())));
    }
  }
}
