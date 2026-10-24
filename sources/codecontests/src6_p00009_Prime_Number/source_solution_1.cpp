#include<iostream>
using namespace std;
int main(){
  bool num[1000000] = {false};
  for(int i=2; i<1000; i++){
    if(!num[i]) for(int j=i*i; j<1000000; j+=i) num[j] = true;
  }
  int n;
  while(cin >>n){
    int ans = 0;
    for(int i=2; i<=n; i++) if(!num[i]) ans++;
    cout <<ans<<endl;
  }
  return 0;
}