#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
	double x1,y1,x2,y2,x,y,d;

	cin>>x1>>y1>>x2>>y2;
	x=abs(x1-x2);y=abs(y1-y2);

	d=sqrt(x*x+y*y);
	printf("%.10f\n",d);
	

}