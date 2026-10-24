//b 点
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,ans=0,x,y;
	cin>>n>>m;
	for (long long i=1;i<=n;++i) {
		cin>>x>>y;
		if (x*x+y*y<=m*m){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 