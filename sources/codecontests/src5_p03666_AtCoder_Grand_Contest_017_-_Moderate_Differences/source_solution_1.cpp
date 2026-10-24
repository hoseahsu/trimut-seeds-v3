#include <bits/stdc++.h>
#define R register
using namespace std;
typedef long long LL;
int u,n,C,D;LL l,ll,r,rr;
int main(){
	cin>>n>>C>>D;u=C-D;cin>>C>>D;--n;ll=(LL)C*n,
	rr=(LL)D*n;for (R int i=n; ~i; --i){
		if (l+ll<=u&&u<=r+rr) return 0*puts("YES");
		ll-=C;rr-=D;
		l-=D;r-=C;
	}puts("NO");
}