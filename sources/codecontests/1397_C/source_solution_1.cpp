#include <bits/stdc++.h>
using namespace std;
int N;
int arr[101010];
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  if (N == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << -arr[0] << endl;
  } else {
    cout << 1 << " " << N << endl;
    for (int i = 0; i < N; ++i) cout << -1LL * arr[i] * N << " ";
    cout << endl;
    cout << 1 << " " << N - 1 << endl;
    for (int i = 0; i < N - 1; ++i) cout << 1LL * arr[i] * (N - 1) << " ";
    cout << endl;
    cout << N << " " << N << endl;
    cout << 1LL * arr[N - 1] * (N - 1) << " ";
    cout << endl;
  }
}
