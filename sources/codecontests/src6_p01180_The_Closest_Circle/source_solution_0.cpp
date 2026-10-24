#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1e10
using namespace std;

int n;
struct P{
	double x,y,r;
	P(){}
	P(double xx,double yy,double rr){
		x=xx;
		y=yy;
		r=rr;
	}
	bool operator<(const P &p1)const{
		return x<p1.x;
	}
};

bool compare_y(P a,P b){
	return a.y<b.y;
}


double closest_pair(P *a,int n){
	if(n<=1)return INF;
	int m=n/2;
	double x=a[m].x;
	double r=a[m].r;
	double d=min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a+m,a+n,compare_y);
	vector<P> b;
	for(int i=0;i<n;i++){
		if(fabs(a[i].x-x)-a[i].r-r>=d)continue;
		for(int j=0;j<b.size();j++){
			double dx=a[i].x-b[b.size()-j-1].x;
			double dy=a[i].y-b[b.size()-j-1].y;
			if(dy>=d+r+a[i].r)break;
			d=min(d,sqrt(dx*dx+dy*dy)-b[b.size()-j-1].r-a[i].r);
		}
		b.push_back(a[i]);
		r=max(a[i].r,r);
	}
	return d;
}

P p[100001];

int main(void){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf",&p[i].r,&p[i].x,&p[i].y);
		}
		sort(p,p+n);
		printf("%.9f\n",closest_pair(p,n));
	}
	return 0;
}