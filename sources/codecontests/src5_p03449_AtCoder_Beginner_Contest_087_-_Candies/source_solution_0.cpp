#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;
int f[3][105];
int a[3][105],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	f[1][1]=a[1][1];
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
		f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
	printf("%d",f[2][n]);
}
