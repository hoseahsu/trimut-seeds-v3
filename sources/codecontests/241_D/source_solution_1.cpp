#include <bits/stdc++.h>
using namespace std;
int data[100050], number[100050], ip[100050];
int Rand() { return (rand() << 15) | rand(); }
int main() {
  int n, p, i, j, vs, temp, result, total;
  srand((unsigned)time(0));
  vs = 0;
  scanf("%d%d", &n, &p);
  for (i = 1; i <= n; i++) {
    scanf("%d", &ip[i]);
    number[ip[i]] = i;
    if (ip[i] <= 25) {
      data[vs++] = ip[i];
    }
  }
  for (i = 0; i < 1 << 25; i++) {
    temp = result = total = 0;
    for (j = 0; j < vs; j++)
      if ((1 << j) & i) {
        total++;
        temp ^= data[j];
        if (data[j] > 9) {
          result = (100 * result + data[j]) % p;
        } else {
          result = (10 * result + data[j]) % p;
        }
      }
    if (temp != 0 || result != 0 || total == 0) {
      continue;
    }
    printf("Yes\n%d\n", total);
    for (j = 0; j < vs; j++)
      if ((1 << j) & i) {
        printf("%d ", number[data[j]]);
      }
    printf("\n");
    return 0;
  }
  printf("No\n");
  return 0;
}
