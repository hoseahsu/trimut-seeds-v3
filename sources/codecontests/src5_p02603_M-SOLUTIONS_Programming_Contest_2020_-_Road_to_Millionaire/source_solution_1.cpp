#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,g=0,q=1000;
	cin>>n;
	int a[n+1];
	for(int i=1; i<=n; i++)	
		cin>>a[i];
	for(int i=1; i<n; i++)
	{
		if(a[i+1]>=a[i])
		{
			g+=q/a[i];
			q%=a[i];
		}
		else
		{
			q+=g*a[i];
			g=0;
		}
	}
	cout<<q+g*a[n];
	return 0;
}