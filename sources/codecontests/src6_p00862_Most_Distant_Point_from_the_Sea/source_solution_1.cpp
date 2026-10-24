#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cfloat>
using namespace std;

const double EPS = 1e-6;

typedef complex<double> P;

double cross(P va, P vb){
	return real(va) * imag(vb) - imag(va) * real(vb);
}

double distanceLP(P a, P b, P c){
	return abs(cross(b - a, c - a)) / abs(b - a);
}

P crosspoint(P pa1, P pa2, P pb1, P pb2){
	P da12 = pa2 - pa1;
	P db21 = pb1 - pb2;
	P dab1 = pb1 - pa1;
	double d = cross(da12, db21);
	if(abs(d) > EPS){
		double t = cross(dab1, db21) / d;
		return pa1 + t * da12;
	}
	return P(DBL_MAX, DBL_MAX);
}

int main(){
	int n;
	P pts[110];
	double x, y;
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf", &x, &y);
			pts[i] = P(x, y);
		}
		pts[n] = pts[0];
		
		double ans = 0.0;
		for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
		for(int k = j + 1; k < n; ++k){
			int e0 = i, e1 = j, e2 = k;

			if(abs(cross(pts[i + 1] - pts[i], pts[j + 1] - pts[j])) < EPS){
				e0 = j;
				e1 = k;
				e2 = i;
			}
			else if(abs(cross(pts[j + 1] - pts[j], pts[k + 1] - pts[k])) < EPS){
				e0 = k;
				e1 = i;
				e2 = j;
			}

			P tmp[4];
			tmp[0] = pts[e0];
			tmp[1] = crosspoint(pts[e0], pts[e0 + 1], pts[e1], pts[e1 + 1]);
			tmp[2] = crosspoint(pts[e1], pts[e1 + 1], pts[e2], pts[e2 + 1]);
			tmp[3] = pts[e2 + 1];
			double a1 = 0.5 * (arg(tmp[2] - tmp[1]) + arg(tmp[0] - tmp[1]));
			double a2 = 0.5 * (arg(tmp[3] - tmp[2]) + arg(tmp[1] - tmp[2]));
			P c = crosspoint(tmp[1], tmp[1] + polar(1.0, a1), tmp[2], tmp[2] + polar(1.0, a2));
			if(real(c) == DBL_MAX){ continue; }
			double d = distanceLP(pts[j], pts[j + 1], c);
			if(d <= ans){ continue; }
			bool ok = true;
			for(int h = 0; h < n && ok; ++h){
				if(distanceLP(pts[h], pts[h + 1], c) < d - EPS){
					ok = false;
				}
				if(cross(pts[h + 1] - pts[h], c - pts[h]) < -EPS){
					ok = false;
				}
			}
			if(ok){
				ans = d;
			}
		}
		printf("%.9f\n", ans);
	}
}