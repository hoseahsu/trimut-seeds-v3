#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef long long lli;
typedef pair<int,int> T;

const int MAXN = 1000006;
const int INF = 1<<29;

class RMQ {
private:
  int n;
  T dat[4*MAXN-1];

public:
  void init(int _n = MAXN, T a = T(INF,INF)) {
    n = 1;
    while(n < _n) n *= 2;
    for(int i = 0; i < 2*n-1; ++i) dat[i] = a;
  }

  void update(int k, T a) {
    k += n-1;
    dat[k] = a;
    while(k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
  }

  T at(int k) {
    return dat[k+n-1];
  }

  T query(int a, int b, int k = 0, int l = 0, int r = 0) {
    if(k == 0) {
      l = 0; r = n;
    }
    if(r <= a || b <= l) return T(INF,INF);
    if(a <= l && r <= b) return dat[k];
    else {
      T v1 = query(a, b, k*2+1, l, (l+r)/2);
      T v2 = query(a, b, k*2+2, (l+r)/2, r);
      return min(v1, v2);
    }
  }
};

RMQ rmq;

int main() {
  int n, q;
  while(cin >> n >> q) {
    rmq.init(n);
    for(int i = 0; i < n; ++i) {
      rmq.update(i, make_pair(0,i));
    }
    for(int i = 0; i < q; ++i) {
      int a, v;
      cin >> a >> v;
      --a;
      pair<int,int> p = rmq.at(a);
      rmq.update(a, T(p.first-v, a));
      p = rmq.query(0,n);
      cout << p.second+1 << " " << -p.first << endl;
    }
  }
  return 0;
}