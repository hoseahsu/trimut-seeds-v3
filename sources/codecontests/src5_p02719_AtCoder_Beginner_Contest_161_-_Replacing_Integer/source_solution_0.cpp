#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t a,b,k1;
  cin >> a >> b;
  k1=a%b;
  cout << min(k1,b-k1) << endl;
}

  
