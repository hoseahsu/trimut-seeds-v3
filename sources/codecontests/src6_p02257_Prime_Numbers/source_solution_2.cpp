#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,num,cnt=0;
	cin >>n;
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		for (int j = 2; j <= sqrt(num);++j)
		{
			if (num%j == 0)
			{
				++cnt;
				break;
			}
		}
	}
	
	cout << n-cnt << endl;

	return 0;

}
