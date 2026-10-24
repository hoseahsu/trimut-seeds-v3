#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int N, D;
  cin >> N >> D;
  vector<int> t(N), F(N);
  for(int i = 0; i < N; i++) {
    cin >> t[i] >> F[i];
  }
  if(t[0] < F[0]-1) {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0, cap = 1;
  for(int i = 1; i < N; i++) {
    if(t[i-1]+(F[i-1]-1)+(F[i]-1) <= t[i]) {
      ans += (F[i-1]-1)*cap;
      cap = 1;
    } else if(t[i-1]+llabs(F[i-1]-F[i]) <= t[i]) {
      ans += (t[i]-t[i-1])*cap;
      cap++;
      if(cap > D) {
	cout << -1 << endl;
	return 0;
      }
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans+(F[N-1]-1)*cap << endl;


  return 0;
}