#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	long long ans=0;
	cin>>n;
	int a,b;
	cin>>a;
	for(int i=1;i<n;i++)
	{
		cin>>b;
		ans+=max(a-b,0);
		a=max(a,b);
	}
	cout<<ans<<endl;
	return 0;
}