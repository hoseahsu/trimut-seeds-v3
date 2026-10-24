#include <bits/stdc++.h>
using namespace std;
int n, a[5000], dolly;
map<int, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    mp[a[i]]++;
  }
  for (int i = 0; i < n; i++)
    if (mp[a[i]] > dolly) dolly = mp[a[i]];
  printf("%d\n", dolly);
}
