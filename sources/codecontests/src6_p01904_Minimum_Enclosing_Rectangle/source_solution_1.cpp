#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
const double EPS = 1e-10;
const double INF = 1e12;
typedef complex<double> P;
typedef pair<P,P> L;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
  }
}
bool cmp(P a,P b) {return atan2(a.imag(),a.real())<atan2(b.imag(),b.real());}
double cross(const P& a, const P& b) {return imag(conj(a)*b);}
double dot(const P& a, const P& b) {return real(conj(a)*b);}
int ccw(P a, P b, P c) {
  b-=a;c-=a;
  if(cross(b,c)>EPS)return +1;
  if(cross(b,c)<-EPS)return -1;
  if(dot(b,c)<-EPS)return +2;
  if(norm(b)<norm(c))return -2;
  return 0;
}
double D(P a, P b) {
  return sqrt((a.real()-b.real())*(a.real()-b.real())+(a.imag()-b.imag())*(a.imag()-b.imag()));
}
P rotate(P a, double r) {
  return P(a.real()*cos(r)-a.imag()*sin(r),a.real()*sin(r)+a.imag()*cos(r));
}
P projection(const L &l, const P &p) {
  double t = dot(p-l.F, l.F-l.S) / norm(l.F-l.S);
  return l.F + t*(l.F-l.S);
}
double toRad(double agl) {return agl*M_PI/180.0;}
double distanceLP(const L &l, const P &p) {
  return abs(p - projection(l, p));
}
vector<P> convex_hull(vector<P> p) {
  int n = p.size(), k = 0;
  sort(p.begin(), p.end());
  vector<P> q(2*n);
  for(int i = 0; i < n; q[k++] = p[i++])
    while(k >= 2 && ccw(q[k-2], q[k-1], p[i]) <= 0) --k;
  for(int i = n-2, t = k+1; i >= 0; q[k++] = p[i--])
    while(k >= t && ccw(q[k-2], q[k-1], p[i]) <= 0) --k;
  q.resize(k-1);
  return q;
}

int main() {
  int n;
  cin >> n;
  vector<P> a;
  a.push_back(P(0,0));
  for(int i=0; i<n-1; i++) {
    int x,y;
    cin >> x >> y;
    P p=a[x],q;
    if(y==0) q=P(p.real()-1,p.imag());
    if(y==1) q=P(p.real(),p.imag()-1);
    if(y==2) q=P(p.real()+1,p.imag());
    if(y==3) q=P(p.real(),p.imag()+1);
    a.push_back(q);
  }
  vector<P> v;
  for(int i=0; i<n; i++) {
    for(int j=0; j<2; j++) {
      for(int k=0; k<2; k++) v.push_back(P(a[i].real()+j,a[i].imag()+k));
    }
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  v=convex_hull(v);
  n=v.size();
  double ans=INF;
  for(int i=0; i<n; i++) {
    rotate(v.begin(),v.begin()+1,v.end());
    P q=rotate(v[1]-v[0],toRad(90+EPS))+v[0];
    L s=L(v[0],v[1]);
    L t=L(v[0],q);
    int l=2,r=n;
    while(l+1<r) {
      int m=(l+r)/2;
      if(ccw(q,v[0],v[m])<0) r=m;
      else l=m;
    }
    int k=l;
    l=2,r=k;
    for(int j=0; j<1000; j++) {
      int m1=(l*2+r)/3,m2=(l+r*2)/3;
      double d1=distanceLP(t,v[m1]),d2=distanceLP(t,v[m2]);
      if(d1<d2) l=m1;
      else r=m2;
    }
    l=(l+r)/2;
    double xx=distanceLP(t,v[l]);
    if(abs(ccw(q,v[0],v[k]))==1) k++;
    l=k,r=n;
    for(int j=0; j<1000; j++) {
      int m1=(l*2+r)/3,m2=(l+r*2)/3;
      double d1=distanceLP(t,v[m1]),d2=distanceLP(t,v[m2]);
      if(d1<d2) l=m1;
      else r=m2;
    }
    l=(l+r)/2;
    xx+=distanceLP(t,v[l]);
    l=2,r=n;
    for(int j=0; j<1000; j++) {
      int m1=(l*2+r)/3,m2=(l+r*2)/3;
      double d1=distanceLP(s,v[m1]),d2=distanceLP(s,v[m2]);
      if(d1<d2) l=m1;
      else r=m2;
    }
    l=(l+r)/2;
    double yy=distanceLP(s,v[l]);
    ans=min(ans,xx*yy);
  }
  printf("%.10f\n",ans);
  return 0;
}
