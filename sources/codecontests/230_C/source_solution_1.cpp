#include <bits/stdc++.h>
char matr[101][10010];
int dist[101][10010];
int main(int argc, const char* argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", &matr[i]);
    for (int j = 0; j < m; j++) dist[i][j] = 1000000;
  }
  for (int i = 0; i < n; i++) {
    bool wasOne = false;
    int distance = 1000000;
    for (int j = 0; j < 2 * m; j++) {
      if (matr[i][j % m] == '1') {
        wasOne = true;
        distance = 0;
      }
      if (distance < dist[i][j % m]) dist[i][j % m] = distance;
      distance++;
    }
    if (!wasOne) {
      printf("-1\n");
      return 0;
    }
    distance = 1000000;
    for (int j = 2 * m - 1; j >= 0; j--) {
      if (matr[i][j % m] == '1') {
        wasOne = true;
        distance = 0;
      }
      if (distance < dist[i][j % m]) dist[i][j % m] = distance;
      distance++;
    }
  }
  int min = 1000000;
  for (int j = 0; j < m; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += dist[i][j];
    if (sum < min) min = sum;
  }
  printf("%d\n", min);
  return 0;
}
