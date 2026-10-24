#include <bits/stdc++.h>
long long maxl = 2147483647;
int main() {
  char s[200];
  scanf("%s\n", s);
  int l = strlen(s);
  if (l > 19) {
    printf("BigInteger\n");
    return 0;
  }
  if (l == 20) {
    if (strcmp(s, "-9223372036854775808") <= 0) {
      printf("long\n");
      return 0;
    } else {
      printf("BigInteger\n");
      return 0;
    }
  }
  if (l == 19) {
    if (strcmp(s, "9223372036854775807") > 0) {
      printf("BigInteger\n");
      return 0;
    } else {
    lng:;
      printf("long\n");
      return 0;
    }
  }
  if (l > 11 || (l == 11 && s[0] != '-') ||
      (l == 10 && strcmp(s, "2147483647") > 0))
    goto lng;
  long long num = atol(s);
  maxl *= -1;
  maxl--;
  if (num < maxl || num > 2147483647) {
    printf("long\n");
    return 0;
  }
  if (num >= -128 && num <= 127) {
    printf("byte\n");
    return 0;
  }
  if (num >= -32768 && num <= 32767) {
    printf("short\n");
    return 0;
  }
  if (num >= maxl && num <= 2147483647) {
    printf("int\n");
    return 0;
  }
  return 0;
}
