#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	d=a*100+b*10+c;
	if(d%4==0) printf("YES\n");
	else printf("NO\n");
}