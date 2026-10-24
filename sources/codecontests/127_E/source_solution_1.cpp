#include <bits/stdc++.h>
using namespace std;
const int oo = 0x7f7f7f7f;
const int Max = 2048;
char mp[Max][Max];
char F[Max];
int N;
int color() {
  int cnt = 0;
  memset(F, 0, sizeof(F[0]) * N);
  for (int i = 0; i < N; i++) {
    int c = 0;
    for (int j = N - 1; j > i; j--) {
      mp[i][j] ^= c ^ F[j];
      if (mp[i][j]) {
        ++cnt;
        mp[i][j] ^= 1;
        c ^= 1;
        F[j] ^= 1;
      }
    }
    mp[i][i] ^= c ^ F[i];
  }
  return cnt;
}
int main() {
  while (scanf("%d", &N) != EOF) {
    for (int i = 0; i < N; i++) {
      scanf("%s", mp[i]);
      for (int j = 0; j < N; j++) mp[i][j] -= '0';
    }
    int Res = color();
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++) swap(mp[i][j], mp[j][i]);
    Res += color();
    for (int i = 0; i < N; i++) Res += mp[i][i];
    printf("%d\n", Res);
  }
  return 0;
}
