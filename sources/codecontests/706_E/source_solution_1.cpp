#include <bits/stdc++.h>
using namespace std;
inline int read_int() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    f |= ch == '-';
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f ? -x : x;
}
typedef struct triple {
  int val, down, right;
} triple;
inline int find_link(int a, int b, int m, int n, triple *arr) {
  int start;
  if (a > b) {
    start = (a - 1) * (m + 1);
    for (int i = 1; i < b; i++) start = arr[start].right;
  } else {
    start = b - 1;
    for (int i = 1; i < a; i++) start = arr[start].down;
  }
  assert(start >= 0 && start < (m + 1) * (n + 1));
  return start;
}
int main() {
  int n = read_int(), m = read_int(), q = read_int();
  triple *arr = (triple *)malloc((n + 1) * (m + 1) * sizeof(triple));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      arr[i * (m + 1) + j].val = read_int();
      arr[(i - 1) * (m + 1) + j - 1].down = i * (m + 1) + j - 1;
      arr[(i - 1) * (m + 1) + j - 1].right = (i - 1) * (m + 1) + j;
    }
    arr[i * (m + 1) - 1].down = (i + 1) * (m + 1) - 1;
  }
  for (int i = 1; i <= m; i++) arr[n * (m + 1) + i - 1].right = n * (m + 1) + i;
  for (int i = 0, a, b, c, d, h, w; i < q; i++) {
    a = read_int(), b = read_int(), c = read_int();
    d = read_int(), h = read_int(), w = read_int();
    int pos1 = find_link(a, b, m, n, arr);
    int pos2 = find_link(c, d, m, n, arr);
    int p, r, j;
    for (p = pos1, r = pos2, j = 0; j < w;) {
      j++;
      p = arr[p].right, r = arr[r].right;
      assert(p > 0 && p < (n + 1) * (m + 1));
      assert(r > 0 && r < (n + 1) * (m + 1));
      swap(arr[p].down, arr[r].down);
    }
    for (j = 0; j < h;) {
      j++;
      p = arr[p].down, r = arr[r].down;
      assert(p > 0 && p < (n + 1) * (m + 1));
      assert(r > 0 && r < (n + 1) * (m + 1));
      swap(arr[p].right, arr[r].right);
    }
    for (p = pos1, r = pos2, j = 0; j < h;) {
      j++;
      p = arr[p].down, r = arr[r].down;
      assert(p > 0 && p < (n + 1) * (m + 1));
      assert(r > 0 && r < (n + 1) * (m + 1));
      swap(arr[p].right, arr[r].right);
    }
    for (j = 0; j < w;) {
      j++;
      p = arr[p].right, r = arr[r].right;
      assert(p > 0 && p < (n + 1) * (m + 1));
      assert(r > 0 && r < (n + 1) * (m + 1));
      swap(arr[p].down, arr[r].down);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1, pos = i * (m + 1); j <= m;) {
      j++;
      pos = arr[pos].right;
      assert(pos > m + 1 && pos < (n + 1) * (m + 1));
      printf("%d ", arr[pos].val);
    }
    putchar('\n');
  }
  free(arr);
  return 0;
}
