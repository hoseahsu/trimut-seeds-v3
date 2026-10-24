#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N],b[N];
int main(){
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=n-1;i>=0;i--){
		if((a[i]+ans)%b[i]) ans+=b[i]-(a[i]+ans)%b[i];
	}
	printf("%lld\n",ans);
	return 0;
}