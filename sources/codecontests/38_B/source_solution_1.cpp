#include <bits/stdc++.h>
int flag[10][10];
void turn(int x, int y) {
  if (x + 1 <= 8) {
    if (y + 2 <= 8) flag[x + 1][y + 2] = 1;
    if (y - 2 >= 1) flag[x + 1][y - 2] = 1;
  }
  if (x - 1 >= 1) {
    if (y + 2 <= 8) flag[x - 1][y + 2] = 1;
    if (y - 2 >= 1) flag[x - 1][y - 2] = 1;
  }
  if (x + 2 <= 8) {
    if (y + 1 <= 8) flag[x + 2][y + 1] = 1;
    if (y - 1 >= 1) flag[x + 2][y - 1] = 1;
  }
  if (x - 2 >= 1) {
    if (y + 1 <= 8) flag[x - 2][y + 1] = 1;
    if (y - 1 >= 1) flag[x - 2][y - 1] = 1;
  }
}
int main() {
  char pos1, pos2;
  int x1, x2, y1, y2, i, j, num;
  scanf("%c%d", &pos1, &y1);
  getchar();
  scanf("%c%d", &pos2, &y2);
  x1 = pos1 - 'a' + 1;
  x2 = pos2 - 'a' + 1;
  memset(flag, 0, sizeof(flag));
  for (i = 1; i <= 8; i++) flag[i][y1] = 1;
  for (i = 1; i <= 8; i++) flag[x1][i] = 1;
  flag[x2][y2] = 1;
  num = 0;
  turn(x1, y1);
  turn(x2, y2);
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++)
      if (!flag[i][j]) num++;
  printf("%d\n", num);
  return 0;
}
