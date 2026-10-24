#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int num,min=999,count;
  cin >> num;
  for(int i=0;i < num;i++) {
    int n;
    cin >> n;
    for(count=0;n%2==0;count++){
      n/=2;
    }
    if(count < min) min=count;
}
  cout << min <<endl;
}