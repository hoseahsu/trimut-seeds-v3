#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
vector<int> arr;
int track[1000006], cnt[3];
int findval(int a, int b) {
  if (a == b)
    return 0;
  else if (a > b)
    return 1;
  else
    return 2;
}
int main() {
  int c1, c2, n, i, flag = 1, val;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &val);
    arr.push_back(val);
  }
  if (n == 1 || n == 2) {
    printf("-1\n");
    return 0;
  }
  for (i = 1; i < n; ++i) {
    if (arr[i] == arr[i - 1])
      track[i] = 0;
    else if (arr[i] > arr[i - 1])
      track[i] = 1;
    else
      track[i] = 2;
  }
  for (i = 1; i < n; ++i) cnt[track[i]]++;
  for (i = 1; i < n - 1; ++i) {
    cnt[track[i]]--;
    cnt[track[i + 1]]--;
    if (arr[i] != arr[i - 1]) {
      c1 = findval(arr[i - 1], arr[i]);
      c2 = findval(arr[i + 1], arr[i - 1]);
      cnt[c1]++;
      cnt[c2]++;
      if (!(cnt[1] == 0 || cnt[2] == 0)) {
        printf("%d %d\n", i + 1, i);
        return 0;
      }
      cnt[c1]--;
      cnt[c2]--;
    }
    if (arr[i] != arr[i + 1]) {
      c1 = findval(arr[i + 1], arr[i - 1]);
      c2 = findval(arr[i], arr[i + 1]);
      cnt[c1]++;
      cnt[c2]++;
      if (!(cnt[1] == 0 || cnt[2] == 0)) {
        printf("%d %d\n", i + 2, i + 1);
        return 0;
      }
      cnt[c1]--;
      cnt[c2]--;
    }
    cnt[track[i]]++;
    cnt[track[i + 1]]++;
  }
  printf("-1\n");
  return 0;
}
