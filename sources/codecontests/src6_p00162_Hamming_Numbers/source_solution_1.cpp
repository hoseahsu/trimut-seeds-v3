#include<iostream>
using namespace std;

int main(){

  int n,m;

  while(cin >> n, n){
    cin >> m;

    int cnt = 0;
    for(int i=n;i<=m;i++){
      int d = i;

      while(!(d%5)) d /= 5;
      while(!(d%3)) d /= 3;
      while(!(d%2)) d /= 2;

      if(d == 1) cnt++;
    }

    cout << cnt << endl;

  }
}