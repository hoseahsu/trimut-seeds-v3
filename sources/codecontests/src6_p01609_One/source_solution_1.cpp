#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// 2次方程式 ax^2 + bx + c = 0の解 (重解を一つにまとめる)
vector<double> quadratic(double a, double b, double c){
  // assert(a != 0);
  if(abs(a) < EPS){
    if(abs(b) < EPS) return vector<double>();
    return vector<double>(1, -c / b);
  }
  double D = b*b - 4*a*c;
  if(D < 0) return vector<double>();
  if(D == 0) return vector<double>(1, -b/(2.0 * a));

  // |b| >> |ac|の時の桁落ちを避けるために
  // x_1 = (-b-sign(b)*sqrt(D))/(2*a), x_2 = c / (a*x_1)を利用する
  vector<double> res;
  int sign = (b >= 0) ? 1 : -1;
  double x1 = (-b - sign * sqrt(D))/(2.0 * a);
  double x2 = c / (a * x1);
  res.push_back(x1);
  res.push_back(x2);
  return res;
}
double f(double a, double b, double c, double x){
  return a * x * x + b * x + c ;
}
double A, B;
double g(double x){
  return sqrt(1 + (A * x + B) * (A * x + B));
}
// 区間[l, r]をN分割し、各区間を2次関数に近似する ->
// 各区間の積分値はh/3 * (f(x) + 4*f(x + h) + f(x + 2 * h)) (h = (r - l) / 2N, x = 0, 2 * h, 4 * h, (N - 2) * h)
double simpson(double l, double r, double f(double), int N){
  double h = (r - l) / (2 * N); 
  double S = f(l) + f(r);
  for(int i = 1; i < 2 * N; i += 2){
    S += 4.0 * f(l + h * i);
  }
  for(int i = 2; i < 2 * N; i += 2){
    S += 2.0 * f(l + h * i);
  }
  return S * h / 3.0;
}

int main(){
  double W, H;
  int N;
  while(cin >> W >> H >> N){
    double a[50], b[50], c[50];
    vector<double> inter_point;
    REP(i, N){
      double p, q;
      cin >> a[i] >> p >> q;
      b[i] = -2 * a[i] * p;
      c[i] = a[i] * p * p + q;
      vector<double> v = quadratic(a[i], b[i], c[i]);
      REP(i, v.size()){
        double x = v[i];
        x = max(0.0, x);
        x = min(W, x);
        bool ok = true;
        REP(i, inter_point.size()) if(abs(x - inter_point[i]) < EPS) ok = false;
        if(ok) inter_point.insert(lower_bound(inter_point.begin(), inter_point.end(), x), x);
      }
    }
    REP(i, N) FOR(j, i + 1, N) {
      vector<double> v = quadratic(a[i] - a[j], b[i] - b[j], c[i] - c[j]);
      REP(k, v.size()){
        double x = v[k];
        x = max(0.0, x);
        x = min(W, x);
        bool ok = true;
        REP(i, inter_point.size()) if(abs(x - inter_point[i]) < EPS) ok = false;
        if(ok) inter_point.insert(lower_bound(inter_point.begin(), inter_point.end(), x), x);
      }
    }
    double ans = 0;
    REP(i, inter_point.size() - 1){
      double lb = inter_point[i], ub = inter_point[i + 1];
      double mid = (lb + ub) / 2;
      int idx = 0;
      REP(j, N) if(f(a[idx], b[idx], c[idx], mid) < f(a[j], b[j], c[j], mid)){
        idx = j;
      }
      if(!(f(a[idx], b[idx], c[idx], lb + EPS) >= - EPS)) continue;
      if(!(f(a[idx], b[idx], c[idx], ub - EPS) >= - EPS)) continue;
      //printf("[%lf, %lf] idx = %d\n", lb, ub, idx);
      A = 2 * a[idx];
      B = b[idx];
      const int N = 1000;
      ans += simpson(lb, ub, g, N);
    }
    assert(!isnan(ans));
    printf("%.16lf\n", ans);
  }
  return 0;
}