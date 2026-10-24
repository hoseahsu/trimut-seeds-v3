#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int v[N];
  for(int i=0; i<N; i++) cin >> v[i];
  sort(v, v+N);
  double ans = v[0] + v[1];
  for(int i=2; i<N; i++) ans += v[i] * pow(2, i-1);
  cout << ans/pow(2, N-1) << endl;
}
