#include <iostream>
#include <algorithm>
#define roop(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,x,a[100],ans;
signed main(){
  cin>>n>>x;
  roop(i,n)cin>>a[i];
  sort(a,a+n);
  roop(i,n){
    if(x>=a[i]){
	  if(i!=n-1){
      x-=a[i];
      ans++;
	  }
	  else if(a[i]==x){
		  ans++;
	  }
    }
  }
  cout<<ans<<endl;
}