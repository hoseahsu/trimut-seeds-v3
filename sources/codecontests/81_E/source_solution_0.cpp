#include <bits/stdc++.h>
using namespace std;
const int maxn = 110000;
int n;
struct Tinit {
  int f, u;
} A[maxn];
struct Tcxx {
  int A, B;
  Tcxx(int _A = 0, int _B = 0) { A = _A, B = _B; }
  inline bool operator<(const Tcxx &b) const {
    return A != b.A ? A < b.A : B < b.B;
  }
  inline Tcxx operator+(const Tcxx &b) const { return Tcxx(A + b.A, B + b.B); }
};
struct Talt {
  int tot;
  struct Tsqy {
    int s;
    Tsqy *l;
    inline void set(Tsqy *_l, int _s) { l = _l, s = _s; }
  } * pos[maxn], buf[maxn];
  inline void add(int a, int b) {
    buf[++tot].set(pos[a], b), pos[a] = buf + tot;
  }
} alt;
namespace Ninit {
void init() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d", &A[i].f, &A[i].u);
    --A[i].u, alt.add(A[i].f, i);
  }
}
}  // namespace Ninit
namespace Nsolve {
Tcxx ans;
vector<Tcxx> B;
bool U[maxn];
namespace Ntree {
Tcxx F[maxn][2];
int G[maxn];
vector<Tcxx> E;
void dfs(int x, int rt) {
  Talt::Tsqy *p;
  Tcxx ret;
  U[x] = true, F[x][0] = F[x][1] = Tcxx();
  for (p = alt.pos[x]; p; p = p->l)
    if (p->s != rt) {
      dfs(p->s, rt);
      F[x][1] = F[x][1] + max(F[p->s][0], F[p->s][1]);
      ret = F[x][0] + F[p->s][0] + Tcxx(1, A[x].u ^ A[p->s].u);
      if (F[x][1] < ret) F[x][1] = ret, G[x] = p->s;
      F[x][0] = F[x][0] + max(F[p->s][0], F[p->s][1]);
    }
}
void constrc(int x, int c, int rt) {
  Talt::Tsqy *p;
  for (p = alt.pos[x]; p; p = p->l)
    if (p->s != rt) {
      if (!c || p->s != G[x])
        constrc(p->s, F[p->s][0] < F[p->s][1] ? 1 : 0, rt);
      else
        E.push_back(Tcxx(x, p->s)), constrc(p->s, 0, rt);
    }
}
void solve(int x) {
  Tcxx Fc;
  int i;
  for (; !U[x]; x = A[x].f) U[x] = true;
  for (i = 0; i < 2; ++i, x = A[x].f) {
    dfs(x, x);
    if (Fc < F[x][1]) {
      Fc = F[x][1];
      E.clear(), constrc(x, 1, x);
    }
  }
  ans = ans + Fc, B.insert(B.end(), E.begin(), E.end());
}
}  // namespace Ntree
void solve() {
  int i;
  vector<Tcxx>::iterator p;
  for (i = 1; i <= n; ++i)
    if (!U[i]) Ntree::solve(i);
  printf("%d %d\n", ans.A, ans.B);
  for (p = B.begin(); p != B.end(); ++p) printf("%d %d\n", p->A, p->B);
}
}  // namespace Nsolve
int main() {
  Ninit::init();
  Nsolve::solve();
  return 0;
}
