#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n,h,i,j,maxi=-1,s=0;
	bool f=0;
	cin>>n>>h;
	int a[n+1],b[n+1];
	for (i=1;i<=n;i++) 
	{
		cin>>a[i]>>b[i];
		if (maxi<a[i]) maxi=a[i];
	}
	
	sort(b+1,b+n+1);
	i=n+1;
	while (i>1 && f==0)
	{
		i--;
		if (b[i]<=maxi) f=1;
		else  if (h<=0) f=1;
		else h-=b[i],s++;
	}
	
	while(h>0)
	{
		s++;
		h-=maxi;
	}
	
	cout<<s;
	return 0;
}