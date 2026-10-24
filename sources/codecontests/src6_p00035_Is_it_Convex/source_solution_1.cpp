#include <complex>
#include <cstdio>
#include <cmath>
using namespace std;

// _ÀWð^Æ·é
typedef complex<double> P;

//XYÀW
#define X real()
#define Y imag()

// ¼üp1,p2Æüªp3,p4Ìð·»è
// (n < 0)<=>ð· , (n == 0)<=>¼üã, (n > 0)<=>ð·µÄ¢È¢  
double isIntersect(P p1, P p2, P p3, P p4){  
    return ( (p1.X-p2.X)*(p3.Y-p1.Y) + (p1.Y-p2.Y)*(p1.X-p3.X)) * ((p1.X-p2.X)*(p4.Y-p1.Y) + (p1.Y-p2.Y)*(p1.X-p4.X));  
}

int main(){
	double xa, xb, xc, xd, ya, yb, yc, yd;

	while( scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd) != EOF ){
		P a( xa , ya );
		P b( xb , yb );
		P c( xc , yc );
		P d( xd , yd );
		
		if( isIntersect(a,c,b,d) > 0.0 || isIntersect(b,d,a,c) > 0.0 ){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}
}