#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  string SS = S+S;
  if (SS.find(T) != -1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
