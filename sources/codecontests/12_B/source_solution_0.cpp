#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j;
int a[50], x;
char b[50];
bool f;
int main() {
  cin >> n;
  i = 1;
  while (n > 0) {
    a[i] = n % 10;
    n = n / 10;
    i++;
  }
  sort(a + 1, a + i);
  if (a[1] == 0) {
    for (j = 2; j < i; j++) {
      if (a[j] > 0) {
        swap(a[1], a[j]);
        break;
      }
    }
  }
  gets(b);
  gets(b);
  x = strlen(b);
  x--;
  j = 0;
  f = true;
  while (j <= x) {
    if (j == 0 && j < x && b[j] == 48) {
      f = false;
      break;
    }
    m = m * 10 + b[j] - 48;
    j++;
  }
  if (!f) {
    printf("WRONG_ANSWER");
    return 0;
  }
  if (n == 0 && m == 0) {
    printf("OK");
    return 0;
  }
  i--;
  n = 0;
  j = 1;
  while (j <= i) {
    n = n * 10 + a[j];
    j++;
  }
  if (m != n) {
    printf("WRONG_ANSWER");
    return 0;
  }
  printf("OK");
  return 0;
}
