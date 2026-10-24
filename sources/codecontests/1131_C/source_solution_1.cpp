#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(int argc, const char *argv[]) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1, greater<int>());
  deque<int> line;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      line.push_front(a[i]);
    } else {
      line.push_back(a[i]);
    }
  }
  for (int x : line) {
    printf("%d ", x);
  }
  return 0;
}
