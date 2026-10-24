#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

int main() {
double r,th=0,x=0,y=0,kaku=0;
char d;
while(1){
	cin>>r>>d>>th;
	if(r==0&&th==0){
		break;
	}
	x=x+r*sin(kaku*PI/180);
	y=y+r*cos(kaku*PI/180);
	kaku=th+kaku;
}
int xx,yy;
xx=x;
yy=y;
cout<<xx<<endl;
cout<<yy<<endl;
	return 0;
}