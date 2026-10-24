#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B, V, W, T;
  cin >> A >> V >> B >> W >> T;
  
  if (abs(B-A)<=(V-W)*T ) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}