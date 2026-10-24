#include <bits/stdc++.h>
using namespace std;
double esp = 0.00000001;
long long int ar[100005];
int main() {
  long long int n;
  cin >> n;
  ar[0] = 0;
  ar[1] = 0;
  ar[2] = 0;
  for (int i = 3; i <= n; i++) {
    set<long long int> grundy;
    for (long long int j = 2;; j++) {
      long long int temp = j * (j + 1) / 2;
      temp = i - temp;
      if (temp < 0) break;
      if (temp % j) continue;
      temp = temp / j;
      long long int val = ar[temp + j] ^ ar[temp];
      if (val == 0 && i == n) {
        cout << j << endl;
        return 0;
      }
      grundy.insert(val);
    }
    long long int ret = 0;
    for (set<long long int>::iterator it = grundy.begin(); it != grundy.end();
         it++) {
      if (*it != ret) break;
      ret++;
    }
    ar[i] = ar[i - 1] ^ ret;
  }
  cout << "-1\n";
  return 0;
}
