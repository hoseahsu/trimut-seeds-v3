
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double PI = atan(1.0)*4;
	double a = 90;
	double x=0, y=0;

	while ( true )
	{
		char c;
		int r,t;
		cin>>r>>c>>t;
		if ( r==0 && t==0 )
			break;

		x += r*cos(a/360.*2*PI);
		y += r*sin(a/360.*2*PI);
		a -= t;
	}

	cout << (int)x << endl;
	cout << (int)y << endl;
	return 0;
}