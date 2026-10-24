#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long A[200005];
int main() {
  ios_base::sync_with_stdio(0);
  int N;
  cin >> N;
  for (int i = 0; i < (2 * N); ++i) {
    cin >> A[i];
  }
  sort(A, A + 2 * N);
  long long result = (A[N - 1] - A[0]) * (A[2 * N - 1] - A[N]);
  for (int i = 0; i < (N + 1); ++i) {
    result = min(result, (A[2 * N - 1] - A[0]) * (A[i + N - 1] - A[i]));
  }
  cout << result << endl;
}
