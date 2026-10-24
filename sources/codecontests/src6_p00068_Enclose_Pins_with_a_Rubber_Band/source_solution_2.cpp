#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

// geometry
typedef long double Real;
#define EPS 1e-12
typedef complex<Real> P;
bool P_less(const P &a,const P &b){
  if(a.real()!=b.real())return a.real()<b.real();
  return a.imag()<b.imag();
}
Real dot(const P &a,const P &b){return real(conj(a)*b);}
Real cross(const P &a,const P &b){return imag(conj(a)*b);}
int ccw(const P &a,const P &b,const P &c){
  Real x = cross(b-a,c-a);
  if(abs(x)<EPS)return 0;
  else if(x<0)return -1;
  else return 1;
}

struct ccw_less{
  P x;
  bool operator()(const P &a,const P &b) const{
    int c = ccw(x,a,b);
    if(c==0) return norm(a-x)<norm(b-x);
    return c==1;
  }
};
vector<P> createConvexHull(vector<P> p){
  // Graham's scan
  vector<P> ret(p.size());
  // ?????????????????????
  int id = 0;
  REPR(i,p.size()) if(P_less(p[i],p[id])) id = i;
  swap(p[0],p[id]);
  // ????§??????????
  ccw_less cw;
  cw.x = p[0];
  sort(p.begin()+1,p.end(),cw);
  // ??°?????????????????£???
  int iter = 0;
  ret[iter++] = p[0];
  REPR(i,p.size()){
    while(iter>=2 && ccw(ret[iter-2],ret[iter-1],p[i])<=0)--iter;
    ret[iter++] = p[i];
  }
  ret.resize(iter);
  return ret;
}

int main(){
  // verify : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0068
  while(true){
    int n;
    scanf("%d",&n);
    if(!n)break;
    vector<P> p(n);
    REP(i,n){
      Real x,y;
      scanf("%Lf,%Lf",&x,&y);
      p[i] = P(x,y);
    }
    vector<P> conv = createConvexHull(p);
    cout<< (n-conv.size()) <<endl;
  }
  return 0;
}