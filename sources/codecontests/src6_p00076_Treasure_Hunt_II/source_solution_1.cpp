#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14159265
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	int n;
	while(cin >> n , n != -1){
		double x = 1.0 , y = 0.0 , degree = PI;
		
		rep(i,n-1){
			degree -= PI / 2.0;
			x += cos(degree);
			y += sin(degree);
			
			double d = max(x,y);
			degree = atan2(y,x) + PI;
		}
		printf("%.2lf\n%.2lf\n",x,y);
	}
}