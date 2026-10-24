#include <bits/stdc++.h>
const int MAXA = 5005;
const int MAXN = 2016;
int array[MAXN]{};
long long diffr[MAXA]{};
long long suffx[MAXA]{};
long double total;
long long Ans = 0;
int N;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) scanf("%d", &array[i]);
  total = N * (N - 1) >> 1;
  std::sort(array, array + N);
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j) ++diffr[array[j] - array[i]];
  for (int i = 5000; i >= 0; --i) suffx[i] = suffx[i + 1] + diffr[i];
  for (int i = 1; i <= 5000; ++i)
    for (int j = 1; i + j <= 5000; ++j)
      Ans += diffr[i] * diffr[j] * suffx[i + j + 1];
  std::cout << std::setprecision(9) << Ans / total / total / total << '\n';
  return 0;
}
