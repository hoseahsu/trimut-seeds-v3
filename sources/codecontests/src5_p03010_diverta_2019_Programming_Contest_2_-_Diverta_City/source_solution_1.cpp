#include<iostream>
#define fr(i,a,b) for(int i=a;i<=b;i++)
int f[]={0,1,2,4,7,12,20,29,38,52,73},n;
int main()
{
	std::cin>>n;
	long d[11][11]={0},p=1;
	fr(i,2,n){fr(j,1,i-1)d[i][j]=d[j][i]=p*f[j];p+=d[i][i-1]+d[i][i-2]-d[i-1][i-2];}
	fr(i,1,n)fr(j,1,n)std::cout<<d[i][j]<<" \n"[j==n];
	return 0;
}