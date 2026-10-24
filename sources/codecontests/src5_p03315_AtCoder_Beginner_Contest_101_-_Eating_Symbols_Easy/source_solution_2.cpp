#include <bits/stdc++.h>
using namespace std;
int main(){
  int i = 0;
  string x;
  cin >> x;
  for (char a : x){
    if (a == '+') i ++;
    else i--;
  }
  cout << i << endl;
}
