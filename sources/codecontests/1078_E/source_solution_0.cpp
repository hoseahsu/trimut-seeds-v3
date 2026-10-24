#include <bits/stdc++.h>
using namespace std;
const long long mod = (1e+9) + 7;
const long long size = 1e+5;
void solve() {
  string s;
  s += "d0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0l0lrr"
       "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrru";
  s += "ddddddd1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l1l"
       "1l1lrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrruuuuuuu";
  for (long long i = 0; i < 32; i++)
    s += "dd0d0d0d0d0uuuuuuuudstdddddddddustustuuuuuudstddddddddustuuuuuu0dl1ru"
         "uu1"
         "dddddstdstdstdstuuuuuudd0d0d0d0d0uuuuuuduudstddstdddddddustustuuuul1r"
         "0u0"
         "duu0dddddstdstdstdstuuuuuuudstdd1dddddstuuuuuul";
  s += "ld";
  cout << s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t beg = clock();
  solve();
  clock_t end = clock();
  fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
  return 0;
}
