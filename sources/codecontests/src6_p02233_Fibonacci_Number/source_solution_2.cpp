# include <iostream>
using namespace std;
int main(void)
{
	int a[50] = {1,1},n;
	for(int i = 2;i < 50;i++) a[i] = a[i-1]+a[i-2];
	cin>>n; cout<<a[n]<<endl;
	return 0;
}
