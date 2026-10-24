#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500 + 10;
int Arr[MAX_N];
map<int, int> m;
int n;
int gcd(int a, int b) {
  if (b > a) swap(a, b);
  return (b == 0 ? a : gcd(b, a % b));
}
int main() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    int temp;
    cin >> temp;
    m[temp]++;
  }
  for (int i = 0; i < n; i++) {
    map<int, int>::reverse_iterator it = m.rbegin();
    while (it->second <= 0) {
      m.erase(it->first);
      it = m.rbegin();
    }
    int key = (it->first);
    m[key]--;
    Arr[i] = key;
    for (int j = 0; j < i; j++) m[gcd(key, Arr[j])]--, m[gcd(Arr[j], key)]--;
  }
  for (int i = 0; i < n; i++) cout << Arr[i] << " ";
  cout << endl;
  return 0;
}
