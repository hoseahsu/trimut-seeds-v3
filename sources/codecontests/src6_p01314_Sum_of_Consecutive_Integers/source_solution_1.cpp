#include<iostream>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

int main(){
  int n;
  while(cin>>n && n){
    int ans=0;
    REP(i,1,n){
      int cur=0;
      REP(j,i,n && cur < n){
	cur+=j;
	if (cur == n)ans++;
      }
    }

    cout << ans << endl;
  }
}