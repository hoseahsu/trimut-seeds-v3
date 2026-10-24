#include <iostream>
using namespace std;
int main()
{
	int a,b,m;
	cin>>a>>b;
	m=b;
	for(int i=1;i<=a-1;i++)
	{
		b*=(m-1);
	}
	cout<<b;
	return 0;
} 
