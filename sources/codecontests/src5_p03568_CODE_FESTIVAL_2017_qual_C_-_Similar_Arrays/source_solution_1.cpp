#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long long i,n,a[11],tmp=1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%2==0)tmp<<=1;
	}
	cout << pow(3,n)-tmp<<"\n";
}
