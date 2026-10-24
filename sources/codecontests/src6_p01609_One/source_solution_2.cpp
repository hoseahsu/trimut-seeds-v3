#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

#define MAX 51
double W,H,a[MAX],p[MAX],q[MAX];
int N;

const bool debug = 0;

typedef pair<double,double> dd;
const double DINF = 1e20;
#define pow2(a) ((a)*(a))

dd calc(double a,double b,double c) {
  dd ret = dd(DINF,DINF);
  double D = b*b - 4 * a * c;

  if( LT(D,0.0) ) return ret;

  if( equals(a,0.0) ) {
    if( equals(b,0.0) ) return ret;
    if( LT(-c/b,0.0)  ) return ret;
    ret.first = - c / b;
    return ret;
  }

  if( equals(D,0.0) ) D = 0;
  ret.first  = ( -b - sqrt( D ) ) / ( 2 * a );
  ret.second = ( -b + sqrt( D ) ) / ( 2 * a );
  if( !equals(ret.first,ret.second) && ret.first > ret.second ) swap(ret.first,ret.second);
  return ret;
}

inline double f(int i,double x) { return a[i] * pow2(x-p[i]) + q[i]; }

inline double fp(int i,double x) { return 2.0 * a[i] * ( x - p[i] ); }

inline double fq(int i,double x) { return sqrt( 1.0 + pow2(fp(i,x)) ); }

vector<double> calc_xp() {
  vector<double> xp;
  xp.push_back(0);
  xp.push_back(W);
  rep(i,N) {
    // 1
    REP(j,i+1,N) {
      dd tmp = calc(a[i]-a[j],-2.0*(a[i]*p[i]-a[j]*p[j]),a[i]*pow2(p[i])+q[i]-a[j]*pow2(p[j])-q[j]);
      if( equals(tmp.first,DINF) ) continue;
      xp.push_back(tmp.first);
      if( debug ) cout << "?1 " << tmp.first << " " << f(i,tmp.first) << " == " << f(j,tmp.first) << endl;
      if( equals(tmp.second,DINF) ) continue;
      xp.push_back(tmp.second);
      if( debug ) cout << "?2 " << tmp.second  << " " << f(i,tmp.second) << " == " << f(j,tmp.second) << endl;
    }
    // 2
    xp.push_back(f(i,0));
    if( debug ) cout << "?3 " << f(i,0) << endl;
    xp.push_back(f(i,W));
    if( debug ) cout << "?4 " << f(i,W) << endl;
    // 3
    {
      dd tmp = calc(a[i],-2.0*a[i]*p[i],a[i]*pow2(p[i])+q[i]);
      if( equals(tmp.first,DINF) ) continue;
      xp.push_back(tmp.first);
      if( debug ) cout << "?5 " << tmp.first << endl;
      if( equals(tmp.second,DINF) ) continue;
      xp.push_back(tmp.second);
      if( debug ) cout << "?6 " << tmp.second << endl;
    }
  }
  //sort(ALL(xp),LT);
  //xp.erase(unique(ALL(xp),LT),xp.end());
  sort(ALL(xp));
  xp.erase(unique(ALL(xp)),xp.end());
  return xp;
}

int find_top(double x) {
  int max_ptr = 0;
  REP(i,1,N) if( LT(f(max_ptr,x),f(i,x)) ) max_ptr = i;
  return max_ptr;
}

double simpson(double a,double b,int n,int id){
  double h = ( b - a ) / n;
  vector<double> x(n+1), fx(n+1);
  for(int i=0;i<=n;++i) {
    x[i]  = a + i * h;
    fx[i] = fq(id,x[i]);
  }
  double resp = 0;
  for(int i=0;i<=n;++i) {
    if( i == 0 || i == n ) resp += fx[i];
    else if( i % 2 != 0 )  resp += 4 * fx[i];
    else                   resp += 2 * fx[i];
  }
  resp = resp * ( h / 3.0 );
  return resp;
}

void compute() {
  vector<double> xp = calc_xp();
  int n = xp.size();
  if( debug ) {
    cout << "* xp" << endl;
    rep(i,(int)xp.size()) cout << "  xp[" << i << "] = " << xp[i] << endl;
    puts("");
  }

  double ans = 0;
  rep(i,n-1) {
    double L = xp[i];
    double R = xp[i+1];
    if( !( LTE(0,L) && LTE(L,W) && LTE(0,R) && LTE(R,W) ) ) continue;
    double M = ( L + R ) / 2.0;
    int ptr = find_top(M);
    if( debug ) {
      cout << "[" << L << "," << R << "]" << endl;
      cout << "  ptr = " << ptr << " and f(" << ptr << "," << M << ") = " << f(ptr,M) << endl;
    }
    
    if( !( LTE(0,f(ptr,M)) && LTE(f(ptr,M),H) ) ) continue;

    double len = simpson(L,R,1000,ptr);

    if( debug ) {
      cout << ans << " += " << "( simpson(" << L << "," << R << "," << ptr << ") = " << len << " )" << endl;
    }
    
    ans += len;
    
    if( debug ) puts("");
  }

  printf("%.10f\n",ans);

}

int main() {
  cin >> W >> H >> N;
  rep(i,N) cin >> a[i] >> p[i] >> q[i];
  compute();
  return 0;
}

