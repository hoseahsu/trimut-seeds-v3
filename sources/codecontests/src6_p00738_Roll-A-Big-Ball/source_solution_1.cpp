#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int n;
int sx,sy,gx,gy;
int xa[SIZE],ya[SIZE],xb[SIZE],yb[SIZE],h[SIZE];

typedef double P_type;
typedef complex<P_type> P;
const P_type P_eps = 1e-8;

//??????
double dot(P a, P b) {
  return (a * conj(b)).real();
}

//??????
double cross(P a, P b) {
  return (a * conj(b)).imag();
}

double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < P_eps ) return abs(c-a);
  if ( dot(a-b, c-b) < P_eps ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

/* ?????????????????? */
bool IntersectionSS(P a1, P a2, P b1, P b2){
    
  //??????a ??¨ ??´???b
  P_type a = cross(b1-b2,a1-b1);
  P_type b = cross(b1-b2,a2-b1);
  
  //??????b ??¨ ??´???a
  P_type c = cross(a1-a2,b1-a1);
  P_type d = cross(a1-a2,b2-a1);
  
  if(a*b < -P_eps && c*d < -P_eps) // T?????????????????? -P_eps
    return true;
  else
    return false;
}

bool check(double r){
  
  P l_s = P(sx,sy);
  P l_g = P(gx,gy);
  
  for(int i=0;i<n;i++){
    P p[4];
    p[0] = P(xa[i],ya[i]);
    p[1] = P(xa[i],yb[i]);
    p[2] = P(xb[i],yb[i]);
    p[3] = P(xb[i],ya[i]);
    double H = min((double)h[i],r);
    double R = sqrt(r*r - (r-H)*(r-H));

    for(int j=0;j<4;j++){
      double dis = distance_ls_p(l_s, l_g, p[j]);
      bool is = IntersectionSS(l_s,l_g,p[j],p[(j+1)%4]);
      bool in = (xa[i] <= sx && sx <= xb[i] && ya[i] <= sy && sy <= yb[i]) ||
        (xa[i] <= gx && gx <= xb[i] && ya[i] <= gy && gy <= yb[i]);
      
      if(dis < R || is || in){
        return false;
      }
    }
  }
  
  for(int i=0;i<n;i++){
    P p[4];
    p[0] = P(xa[i],ya[i]);
    p[1] = P(xa[i],yb[i]);
    p[2] = P(xb[i],yb[i]);
    p[3] = P(xb[i],ya[i]);
    double H = min((double)h[i],r);
    double R = sqrt(r*r - (r-H)*(r-H));

    for(int j=0;j<4;j++){
      double dis1 = distance_ls_p(p[j],p[(j+1)%4],l_s);
      double dis2 = distance_ls_p(p[j],p[(j+1)%4],l_g);
      
      if(dis1 < R || dis2 < R){
        return false;
      }
    }

  }
  
  return true;
}

bool solve(){
  
  
  scanf("%d",&n);

  if(n == 0) return false;

  scanf("%d%d%d%d",&sx,&sy,&gx,&gy);

  for(int i=0;i<n;i++){
    scanf("%d%d%d%d%d",xa+i, ya+i, xb+i, yb+i, h+i);
  }

  double l=0, r=1000;

  while(r-l > 1e-8){
    double mid = (l+r)/2;

    if(check(mid)){
      l = mid;
    }else{
      r = mid;
    }
  }

  printf("%.7lf\n",l);
  
  return true;
}

int main(){

  while(solve());
  
  return 0;
}