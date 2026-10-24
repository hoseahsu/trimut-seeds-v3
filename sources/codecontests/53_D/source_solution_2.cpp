#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:836777216")
using namespace std;
int a[305];
int b[305];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int(i) = 0; (i) < (n); (i)++) {
    scanf("%d", &a[i]);
  }
  for (int(i) = 0; (i) < (n); (i)++) {
    scanf("%d", &b[i]);
  }
  vector<pair<int, int> > v;
  for (int(i) = 0; (i) < (n); (i)++) {
    if (a[i] != b[i]) {
      for (int(j) = (i + 1); (j) < (n); (j)++) {
        if (b[j] == a[i]) {
          int start = j;
          while (start != i) {
            v.push_back(make_pair(start - 1, start));
            swap(b[start - 1], b[start]);
            start--;
          }
          break;
        }
      }
    }
  }
  printf("%d\n", (int)(v).size());
  for (int(i) = 0; (i) < ((int)(v).size()); (i)++) {
    printf("%d %d\n", v[i].first + 1, v[i].second + 1);
  }
}
