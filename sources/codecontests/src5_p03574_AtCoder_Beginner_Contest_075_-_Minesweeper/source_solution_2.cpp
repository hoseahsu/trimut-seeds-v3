#include<cstdio>
#include<iostream>
using namespace std;
const int step[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
char a[55][55];
int s[55][55];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    cin>>a[i][j];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    if(a[i][j]=='.')
	      for(int k=0;k<8;k++)
	        if(a[i+step[k][0]][j+step[k][1]]=='#') s[i][j]++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		  if(a[i][j]=='#') putchar('#');
		  else printf("%d",s[i][j]);
		puts("");
	}
	return 0;
}