#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  
  int inf = pow(10, 9);

  for(int i = 0; i < n; i++){
    if(i < k) cout << s << " ";
    else{
      if(s < inf) cout << inf << " ";
      else cout << 1 << " ";
    }
  }
  cout << endl;
}