#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (max(a,max(b,c)) == a+b+c - max(a,max(b,c)) ? "Yes" : "No");
}