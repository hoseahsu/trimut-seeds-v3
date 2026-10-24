#include<bits/stdc++.h>
using namespace std;
int n,i,a[100002];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]),a[i]=gcd(a[i],a[i-1]);
	printf("%d",a[n]);
}