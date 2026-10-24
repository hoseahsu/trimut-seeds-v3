#include <bits/stdc++.h>
using namespace std;
inline void get_int(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline void get_long(long long int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline void print_int(int X) {
  if (X < 0) {
    putchar('-');
    X = -X;
  }
  int Len = 0, Data[20];
  while (X) {
    Data[Len++] = X % 10;
    X /= 10;
  }
  if (!Len) Data[Len++] = 0;
  while (Len--) putchar(Data[Len] + 48);
  putchar('\n');
}
inline void print_long(long long int X) {
  if (X < 0) {
    putchar('-');
    X = -X;
  }
  int Len = 0, Data[20];
  while (X) {
    Data[Len++] = X % 10;
    X /= 10;
  }
  if (!Len) Data[Len++] = 0;
  while (Len--) putchar(Data[Len] + 48);
  putchar('\n');
}
long long int modPow(long long int a, long long int x, long long int p) {
  long long int res = 1;
  while (x > 0) {
    if (x & 1) {
      res = (res * a) % p;
    }
    a = (a * a) % p;
    x /= 2;
  }
  return res;
}
long long int arr[5005];
long long int pas[5005][5005];
void init() {
  for (int i = 0; i < 2222; i++)
    for (int j = 0; j < 2222; j++) pas[0][j] = pas[i][j] = 1;
  for (int i = 2; i < 2222; i++)
    for (int j = 1; j < i; j++) {
      pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
      pas[i][j] %= 1000000007;
    }
}
int main() {
  init();
  long long int i, k;
  long long int s = 0;
  get_long(k);
  for (i = 0; i <= k - 1; i++) {
    get_long(arr[i]);
    s += arr[i];
  }
  s -= 1;
  long long int ans = 1;
  for (i = k - 1; i >= 0; i--) {
    ans *= pas[s][arr[i] - 1];
    ans %= 1000000007;
    s -= arr[i];
  }
  print_long(ans);
  return 0;
}
