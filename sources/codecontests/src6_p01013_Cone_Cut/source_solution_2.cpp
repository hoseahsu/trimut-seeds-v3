#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

/* 3次元幾何 */

typedef double P_type;
typedef double G_real; //実数の戻り値(float or double or long double)
const G_real P_eps = 1e-8; //整数の時はゼロ

struct P3{
  P_type x, y, z;
  P3(): x(0), y(0), z(0) {}
  P3(P_type x, P_type y, P_type z): x(x), y(y), z(z) {}

  P3 operator-() const {
    return P3(-x, -y, -z);
  }

  P3 operator+(const P3 &B) const {
    return P3(x + B.x, y + B.y, z + B.z);
  }

  P3 operator-(const P3 &B) const {
    return P3(x - B.x, y - B.y, z - B.z);
  }

  P3 operator*(P_type a) const {
    return P3(x * a, y * a, z * a);
  }

  P3 operator/(P_type a) const {
    return P3(x / a, y / a, z / a);
  }

  P3& operator+=(const P3 &B) {
    x += B.x; y += B.y; z += B.z;
    return *this;
  }

  P3& operator-=(const P3 &B) {
    x -= B.x; y -= B.y; z -= B.z;
    return *this;
  }

  P3& operator*=(P_type a) {
    x *= a; y *= a; z *= a;
    return *this;
  }

  P3& operator/=(P_type a) {
    x /= a; y /= a; z /= a;
    return *this;
  }

  bool operator<(const P3 &b){
    if (abs(x - b. x) > P_eps) return x + P_eps < b.x;
    if (abs(y - b. y) > P_eps) return y + P_eps < b.y;
    return z + P_eps < b.z;
  }
};

ostream& operator<<(ostream &st, const P3 &p){
  return st << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

P_type dot(P3 a, P3 b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

P3 cross(P3 a, P3 b) {
  P_type x = a.y * b.z - a.z * b.y;
  P_type y = a.z * b.x - a.x * b.z;
  P_type z = a.x * b.y - a.y * b.x;
  return P3(x, y, z);
}

P_type norm(P3 a) {
  return dot(a, a);
}

double abs(P3 a) {
  return sqrt(dot(a, a)); //sqrtl
}

/* ベクトルa, bの成す角[0, pi] */
G_real arg(P3 a, P3 b) {
  return acos(dot(a, b) / abs(a) / abs(b)); //acosl
}

/* 点Aの平面Plへの正射影 */
P3 getProject(P3 a, P3 pl1, P3 pl2, P3 pl3) {
  P3 n = cross(pl2 - pl1, pl3 - pl1);
  n /= abs(n);
  return a - n * dot(n, a - pl1);
}

/* 直線abと点cの距離 */
G_real distanceLP(P3 a, P3 b, P3 c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}

/* 線分abと点cの距離 */
G_real distanceSP(P3 a, P3 b, P3 c) {
  if (dot(b-a, c-a) <= P_eps) return abs(c-a);
  if (dot(a-b, c-b) <= P_eps) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

/* 直線Aと直線Bの距離 (未検証) */
G_real distanceLL(P3 a1, P3 a2, P3 b1, P3 b2) {
  P3 n = cross(a2 - a1, b2 - b1);
  if (abs(n) <= P_eps) return distanceLP(a1, a2, b1); //平行
  return abs(dot(n, b1 - a1)) / abs(n);
}

/* 線分Aと線分Bの距離(未検証) */
G_real distanceSS(P3 a1, P3 a2, P3 b1, P3 b2) {
  //ねじれの位置
  P3 n = cross(a2 - a1, b2 - b1);
  if (abs(n) > P_eps) { // 平行ではない
    n /= abs(n);
    G_real d = distanceLL(a1, a2, b1, b2);
    P3 p = n * dot(n, b1 - a1);
    P3 c1 = b1 + p, c2 = b2 + p;

    P3 va = a2 - a1, vc = c2 - c1;
    bool f1 = dot(cross(va, c1 - a1), cross(va, c2 - a1)) < -P_eps;
    bool f2 = dot(cross(vc, a1 - c1), cross(vc, a2 - c1)) < -P_eps;

    if (f1 && f2) return d;
  }

  //その他
  return min({distanceSP(a1, a2, b1), distanceSP(a1, a2, b2),
              distanceSP(b1, b2, a1), distanceSP(b1, b2, a2)});
}

/* 点と平面Plの距離 (未検証) */
G_real distancePPl(P3 p, P3 pl1, P3 pl2, P3 pl3) {
  P3 n = cross(pl2 - pl1, pl3 - pl1);
  assert(abs(n) > P_eps); //3点が同一直線上でない
  return abs(dot(p - pl1, n)) / abs(n);
}

/* 直線Aと、平面Plの交点 */
// verified: AOJ0115
vector<P3> getCrosspointLPl(P3 a1, P3 a2, P3 pl1, P3 pl2, P3 pl3) {
  P3 n = cross(pl2 - pl1, pl3 - pl1); //平面の法線ベクトル
  if (abs(dot(n, a2 - a1)) <= P_eps)
    return {}; //平面と直線が平行

  G_real s = dot(pl1 - a1, n), t = dot(a2 - pl1, n);
  P3 c = a1 + (a2 - a1) * (s / (s + t));
  return {c};
}

/* 線分Aと、平面Plの交点 */
// verified: AOJ0115
vector<P3> getCrosspointSPl(P3 a1, P3 a2, P3 pl1, P3 pl2, P3 pl3) {
  auto cps = getCrosspointLPl(a1, a2, pl1, pl2, pl3);
  if (cps.empty()) return {};
  if (norm(a1 - cps[0]) > norm(a1 - a2) + P_eps) return {};
  if (norm(a2 - cps[0]) > norm(a1 - a2) + P_eps) return {};
  return cps;
}

/* 直線A, Bの交点 */
vector<P3> getCrosspointLL(P3 a1, P3 a2, P3 b1, P3 b2) {
  if (distanceLL(a1, a2, b1, b2) > P_eps) return {};
  P3 a = a2 - a1, b = b2 - b1;
  a /= abs(a); b /= abs(b);
  P_type t = dot(a, b);
  return {a1 + a * dot(a1 - b1, a - b * t) / (t * t - 1)}; //ねじれの位置のときは、A側の最近点
}

P3 scan() {
  P_type x, y, z;
  cin >> x >> y >> z;
  return P3(x, y, z);
}


int main(){
  P3 T, O, P;
  int r;

  T = scan();
  O = scan();
  cin >> r;
  P = scan();

  P3 n = T - O;
  n /= abs(n);

  P3 s, t;

  if (abs(n.z) > P_eps)
    s = P3(1, 1, - (n.x + n.y) / n.z);
  else if (abs(n.x) > P_eps)
    s = P3(- (n.z + n.y) / n.x, 1, 1);
  else
    s = P3(1, - (n.x + n.z) / n.y, 1);

  s = s / abs(s) * r;
  t = cross(n, s);
  t = t / abs(t) * r;

  P3 Q = getProject(P, O, s + O, t + O);
  P3 A, B;

  if (abs(Q - O) < P_eps) {
    A = s + O;
    B = -s + O;
  } else {
    A = (Q - O) * r / abs(Q - O) + O;
    B = -(A - O) + O;
  }

  P3 E = cross(A - O, T - O);
  E *= r / abs(E);
  E += O;

  auto cp1 = getCrosspointLL(A, P, B, T);
  auto cp2 = getCrosspointLL(B, P, A, T);

  assert(cp1.size() && cp2.size());

  P3 C = cp1[0], D = cp2[0];

  P_type l1 = abs(C - D) / 2;
  P_type hT = abs(T - O);

  P3 G = (C + D) / 2.0;
  P_type hM = distancePPl(G, A, E, O);
  P_type dM = distanceLP(T, O, G);
  P_type rM = r * (hT - hM) / hT;

  P_type l2 = sqrtl(rM * rM - dM * dM);

  P3 F = G + (E - O);

  P_type ans = M_PI * l1 * l2 * distancePPl(T, C, D, F) / 3.0;
  P_type ans2 = abs(T - O) * r * r * M_PI / 3.0 - ans;

  printf("%.6lf %.6lf\n", (double)ans, (double)ans2);

  return 0;
}

