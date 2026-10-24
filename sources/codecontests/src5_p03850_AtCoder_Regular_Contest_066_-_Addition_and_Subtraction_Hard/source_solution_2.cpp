#include <bits/stdc++.h>
using namespace std;
const int N=100005;
#define ll long long
ll f[N][3],x;char s;
int main (){
	int n;cin>>n;
	cin>>f[0][0];f[0][1]=f[0][2]=-1ll<<60;
	for (int i=1;i<n;i++){
		cin>>s>>x;
		if (s=='+'){
			f[i][0]=max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+x;
			f[i][1]=max(f[i-1][1],f[i-1][2])-x;
			f[i][2]=f[i-1][2]+x;
		}else{
			f[i][0]=max(max(f[i-1][0],f[i-1][1]),f[i-1][2])-x;
			f[i][1]=max(max(f[i-1][1],f[i-1][2])+x,f[i-1][0]-x);
			f[i][1]=max(max(f[i-1][1],f[i-1][2])-x,f[i][1]);
			f[i][2]=max(max(f[i-1][2]-x,f[i-1][2]+x),f[i-1][1]+x);
		}
	}
	printf ("%lld",max(max(f[n-1][0],f[n-1][1]),f[n-1][2]));
	return 0;
}