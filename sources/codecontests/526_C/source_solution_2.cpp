#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N, S1, V1, S2, V2;
  cin >> N >> V1 >> V2 >> S1 >> S2;
  long long ret = 0;
  if (S1 > S2) swap(S1, S2), swap(V1, V2);
  if (S2 > sqrt(N)) {
    for (int i = 0; i * S2 <= N; i++) {
      ret = max(ret, (N - i * S2) / S1 * V1 + i * V2);
    }
  } else {
    if (V1 * S2 > V2 * S1) swap(S1, S2), swap(V1, V2);
    for (int i = 0; i <= S2 && N - S1 * i >= 0; i++) {
      ret = max(ret, (N - i * S1) / S2 * V2 + i * V1);
    }
  }
  cout << ret;
  return 0;
}
