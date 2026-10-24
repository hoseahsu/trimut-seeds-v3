#include <bits/stdc++.h>
using namespace std;

int N, t, sum;
string X, s;
map<string, int> M;

int main() {
  cin >> N;
  while (N-- && cin >> s >> t) M[s] = sum += t;
  cin >> X;

  cout << sum - M[X];
}