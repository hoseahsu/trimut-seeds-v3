#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
 	ios::sync_with_stdio(false);
  long x;
  cin >> x;
  bitset<32> a(x);
  cout << a << "\n";
  cout << ~a << "\n";
  cout << (a<<1) << "\n";
  cout << (a>>1) << "\n";
  return 0;
}
