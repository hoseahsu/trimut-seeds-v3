#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, a, s = 0;
  cin >> n;
  for(int i = 0;i < n;i++) {
    cin >> a;
    if(a == s + 1) s++;
  }
  cout << ((s == 0) ? -1 : n - s) << endl;
}