#include <iostream>
using namespace std;

int n;
double ps[16],pe[16];
struct par { double s,t;};
struct point { int x,y; double s[16],e[16];};
point pt[16];
par linecross(point p1,point p2,point p3,point p4) {
	double a,b,c,d,e,f;
	par p;
	a=p2.x-p1.x;b=p2.y-p1.y;c=p4.x-p3.x;d=p4.y-p3.y;e=p3.x-p1.x;f=p3.y-p1.y;
	if (a*d-b*c==0) {p.s=0; p.t=0; return p;}
	p.t=(b*e-a*f)/(a*d-b*c);
	p.s=(d*e-c*f)/(a*d-b*c);
	return p;
	}
int ckcr(point p1,point p2) {
	int i;
	par p;
	for (i=0;i<n;i++) {
		p=linecross(p1,p2,pt[i],pt[(i+1) % n]);
		if (p.s>0 && p.s<1 && p.t>0 && p.t<1) return 1;
			}
	return 0; 
	}
		
int lineck(int k) {
	int i,j;
	double d=0,m;
	for (i=0;i<k-1;i++) for (j=k-2;j>=i;j--) 
	 if (ps[j]>ps[j+1]) { m=ps[j]; ps[j]=ps[j+1]; ps[j+1]=m; m=pe[j]; pe[j]=pe[j+1]; pe[j+1]=m;}
	 for (i=0;i<k;i++) {
		if (ps[i]>d) return 3;
		if (pe[i]>d) d=pe[i];
		}
		if (d<1) return 1;
		return 0;
	}
	
int range(int p1,int p2) {
	int i,s,a,b,c,d,sp,ep,cp,p3;
	double e,w;
	par x;
	point f;
	p3=(p2+1) % n;
	a=pt[p1].x-pt[p2].x; b=pt[p1].y-pt[p2].y; c=pt[p1].x-pt[p3].x; d=pt[p1].y-pt[p3].y;
	if (a*(pt[p3].y-pt[p2].y)+b*(pt[p2].x-pt[p3].x)==0) {
		if ((a*a+b*b)>(c*c+d*d)) { sp=p2; ep=p1;} else { sp=p1; ep=p3;}
		for (cp=sp; cp!=ep; cp=(cp+1) % n){
			if ((pt[cp].y-pt[sp].y)*(pt[ep].x-pt[sp].x)-(pt[sp].x-pt[cp].x)*(pt[ep].y-pt[sp].y)==0) 
			if ((pt[(cp+1) % n].x-pt[cp].x)*(pt[p3].y-pt[p2].y)+(pt[(cp+1) % n].y-pt[cp].y)*(pt[p2].x-pt[p3].x)<0) return 1;
			}
  		if (ckcr(pt[p1],pt[p2])==0) {pt[p2].s[p1]=0; pt[p2].e[p1]=1; return 0;}
  		 else return 1;
  		}
	s=(pt[p3].y-pt[p2].y)*(pt[p1].x-pt[p2].x)+(pt[p2].x-pt[p3].x)*(pt[p1].y-pt[p2].y);
	if (s>0) return 1;
	e=-1; s=0; w=0;	
	for (i=p2;i!=p1;i=(i+n-1)%n) { 
		x=linecross(pt[p1],pt[i],pt[p2],pt[p3]);
		if (x.s>=1 && x.t>=0 && x.t<=1 && x.t>e) {e=x.t; w=x.s; s=i;}
		}
		f.x=pt[p1].x+w*(pt[s].x-pt[p1].x); f.y=pt[p1].y+w*(pt[s].y-pt[p1].y);
		if (ckcr(pt[p1],f)!=0) return 1;
	    pt[p2].s[p1]=e;
		e=2;s=0; w=0;
	for (i=p3;i!=p1;i=(i+1)%n) {
		x=linecross(pt[p1],pt[i],pt[p2],pt[p3]);
		if (x.s>=1 && x.t>=0 && x.t<=1 && x.t<e) {e=x.t; w=x.s; s=i;}
		}
		f.x=pt[p1].x+w*(pt[s].x-pt[p1].x); f.y=pt[p1].y+w*(pt[s].y-pt[p1].y);
		if (ckcr(pt[p1],f)!=0) return 1;
		pt[p2].e[p1]=e;	
		
	return 0;
	}
 int num(int k,int s,int u) {
 	int i,j,m,h,t;
 	for (i=s;i<k;i++) {
 		h=u+(1 << i);
 		if (s==0) {
 			for (m=0;m<n;m++) {
 			for (j=0,t=0;j<n;j++) if ((h & (1 << j))>0) {ps[t]=pt[m].s[j]; pe[t]=pt[m].e[j];t++;}
 			if (lineck(t)>0) break;
 			 }
 			if (m==n) return 1;
 			}
 		else { if (num(i,s-1,h)>0) return 1;}
 			}
 		return 0;
 		}
int main () {
	int i,j;
	while(true) {
		cin >> n;
		if (n==0) break;
		for (i=0;i<n;i++) cin >> pt[i].x >> pt[i].y;
		for (i=0;i<n;i++) for (j=0;j<n;j++) if (i==j || ((i+n-1) %n)==j) { pt[j].s[i]=0; pt[j].e[i]=1;} else { 
			if (range(i,j)>0) {pt[j].s[i]=0; pt[j].e[i]=0;}}
		for (i=0;i<n;i++) if (num(n,i,0)>0) break;
		cout << i+1 << endl;
		}
	return 0;
    }
	
