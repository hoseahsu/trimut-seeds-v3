#include <bits/stdc++.h>
using namespace std;
const int mx = 10000;
int arr[mx];
int main() {
  int a, b, t, res, mx;
  double x;
  scanf("%d %d", &a, &b);
  vector<pair<int, double> > v;
  for (int i = 0; i < a; i++) {
    cin >> t >> x;
    v.push_back(make_pair(t, x));
  }
  arr[0] = 1;
  for (int i = 1; i < a; i++) {
    arr[i] = 1;
    for (int j = 0; j < i; j++) {
      if (v[i].first >= v[j].first) {
        if (arr[j] + 1 > arr[i]) {
          arr[i] = arr[j] + 1;
        }
      }
    }
  }
  mx = *max_element(arr, arr + a);
  res = a - mx;
  printf("%d\n", res);
}
