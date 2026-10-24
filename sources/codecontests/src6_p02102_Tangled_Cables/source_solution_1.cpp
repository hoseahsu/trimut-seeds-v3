#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int n,m;
pair<pii,pii> edges[12525];

int data[12525];
void init(){
  REP(i,n)data[i] = -1;
}
int root(int x){
  return data[x]<0?x:data[x]=root(data[x]);
}
int unite(int a,int b){
  a=root(a);
  b=root(b);
  if(a!=b){
    if(data[a]>data[b])swap(a,b);
    data[a] += data[b];
    data[b] = a;
    return 1;
  }else{
    return 0;
  }
}

int main(){
  scanf("%d%d",&n,&m);
  ll csum=0, dsum=0;
  REP(i,m){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    csum += c;
    dsum += d;
    edges[i] = make_pair(pii(a,b),pii(c,d));
  }
  if(m==n-1){
    puts("0");
    return 0;
  }
  double low = 0, high = 1e12;
  REP(_,100){
    double t = (low+high)/2;
    vector<pair<double,pii>> es(m);
    REP(i,m){
      double cost = t * edges[i].second.first - edges[i].second.second;
      es[i] = make_pair(cost, edges[i].first);
    }
    sort(ALL(es));
    init();
    int x = n-1;
    double sum = 0.0;
    REP(i,m){
      double cost = es[i].first;
      int a = es[i].second.first;
      int b = es[i].second.second;
      if(unite(a,b)){
        sum += cost;
        x--;
        if(x==0)break;
      }
    }
    double clc = dsum - t*csum + sum;
    if(clc <= 0.0){
      high = t;
    }else{
      low = t;
    }
  }
  printf("%.9f\n",low);
  return 0;
}