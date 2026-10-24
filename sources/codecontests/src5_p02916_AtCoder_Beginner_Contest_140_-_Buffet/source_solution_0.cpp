#include <bits/stdc++.h>
using namespace std;
int n,a[201],b[201],c[201];
int main()
{
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),sum+=b[i];
	for(int i=1;i<n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
	if(a[i]+1==a[i+1])
		sum+=c[a[i]];
	printf("%d\n",sum);
	return 0;
}