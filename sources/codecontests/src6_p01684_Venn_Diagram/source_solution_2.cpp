#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for(int i = (a); i <= int(b); ++i)
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BR putchar('\n')
#define MS0(ar) memset(ar, 0, sizeof(ar))
#define MS1(ar) memset(ar, -1, sizeof(ar))
#define F first
#define S second
#define MP make_pair
#define MT make_tuple

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef complex<double> CD;

void R(int &x) { scanf("%d", &x); }
void R(LL &x) { scanf("%lld", &x); }
void R(ULL &x) { scanf("%llu", &x); }
void R(double &x) { scanf("%lf", &x); }
void R(LD &x) { scanf("%Lf", &x); }

template<typename T>
void R(T &t) { cin >> t; }
template<typename T>
void R(vector<T> &ar) { for(auto &it : ar) R(it); }

template<typename T, typename... Args>
void R(T &t, Args&... args) {
	R(t);
	R(args...);
}

void W(const char &c) { putchar(c); };
void W(const int &x) { printf("%d", x); }
void W(const LL &x) { printf("%lld", x); }
void W(const ULL &x) { printf("%llu", x); }
void W(const double &x) { printf("%lf", x); }
void W(const LD &x) { printf("%Lf", x); }

template<typename T>
void W(const T &t) { cout << t; }
template<typename T>
void W(const vector<T> &ar) {
	for(size_t i = 0; i < ar.size(); ++i) {
		W(ar[i]);
		putchar(" \n"[i + 1u == ar.size()]);
	}
}
template<typename T, typename... Args>
void W(const T &t, const Args&... args) {
	W(t);
	W(args...);
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;

const double pi = acos(-1);

double a,b,c;

double ff(double a, double r) {
  if (a > r) return 0;
  return sqrt(r * r - a * a) * 2;
}
double F(double x) {
  return min(ff(fabs(x), a), ff(fabs(x - c), b));
}

double simpson(double a, double b) {
  double c = a + (b - a) / 2;
  return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}
double asr(double a, double b, double eps, double A) {
  double c = a + (b - a) / 2;
  double L = simpson(a, c), R = simpson(c, b);
  if (fabs(L + R - A) <= 15 * eps)
    return L + R + (L + R - A) / 15.0;
  return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}
double asr(double a, double b, double eps) {
  return asr(a, b, eps, simpson(a, b));
}

double f(double R, double r, double d) {
  a = R, b = r, c = d;
  return asr(max(-R, d - r), min(d + r, R), eps);
}

int main() {
	int w, h, a, b, ab;
  while (scanf("%d%d%d%d%d", &w, &h, &a, &b, &ab) == 5) {
    if (!w && !h && !a && !b && !ab)
      break;
    bool fg = false;
    if (a < b) { swap(a, b); fg = true; }
    double ra = sqrt(a / pi);
    double rb = sqrt(b / pi);
    if (ra * 2 > h + eps || rb * 2 > h + eps || ra * 2 > w + eps || rb * 2 > w + eps) {
      puts("impossible");
      continue;
    }
    double l = 0, r = w - ra - rb;
    while (r - l > 1e-9) {
      double m = (l + r) / 2;
      double area = f(ra, rb, m);
      if (area >= ab) {
        l = m;
      }
      else {
        r = m;
      }
    }
    double dx = l;
    l = 0, r = h - ra - rb;
    while (r - l > 1e-9) {
      double m = (l + r) / 2;
      double area = f(ra, rb, hypot(dx, m));
      if (area >= ab) {
        l = m;
      }
      else {
        r = m;
      }
    }
    double dy = l;

    double area = f(ra, rb, hypot(dx, dy));
    if (fabs(area - ab) > 1e-6) {
      puts("impossible");
      continue;
    }
    double xa = ra, ya = ra;
    double xb = xa + dx, yb = ya + dy;
    if (fg) {
      swap(a, b);
      swap(xa, xb);
      swap(ya, yb);
      swap(ra, rb);
    }
    printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xa, ya, ra, xb, yb, rb);
  }
  return 0;
}