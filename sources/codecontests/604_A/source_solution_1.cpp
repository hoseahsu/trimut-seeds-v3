#include <bits/stdc++.h>
int main() {
  int score[5], wrong_answer[5], hacks = 0, right, wrong,
                                 highest[5] = {2, 4, 6, 8, 10},
                                 ini[5] = {150, 300, 450, 600, 750}, sum = 0, i;
  for (i = 0; i < 5; i++) scanf("%d", &score[i]);
  for (i = 0; i < 5; i++) scanf("%d", &wrong_answer[i]);
  scanf("%d %d", &right, &wrong);
  hacks = right * 100 + (wrong * (-50));
  for (i = 0; i < 5; i++) {
    sum = sum +
          (ini[i] > ((250 - score[i]) * (highest[i]) - (50 * wrong_answer[i]))
               ? ini[i]
               : ((250 - score[i]) * (highest[i]) - (50 * wrong_answer[i])));
  }
  printf("%d\n", sum + hacks);
  return 0;
}
