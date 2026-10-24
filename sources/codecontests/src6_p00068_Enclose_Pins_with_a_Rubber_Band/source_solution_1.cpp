#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

double EPS = 1e-9;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double k) const { return Point(k * x, k * y); }
    Point operator/(double k) const { return Point(x / k, y / k); }
};
double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
double norm(const Point& a) { return sqrt(dot(a, a)); }
Point rot90(const Point& p) { return Point(-p.y, p.x); } // 反時計回りに90度回転 
ostream& operator<<(ostream& os, const Point& p) { return os << "(" << p.x << "," << p.y << ")"; }
istream& operator>>(istream& is, Point& p) { char c; return is >> p.x >> c >> p.y; }

int ccw(Point a, Point b, Point c){
    b = b - a; c = c - a;
    if (cross(b, c) > EPS) return +1;      // a,b,cの順に反時計周り
    if (cross(b, c) < -EPS) return -1;     // a,b,cの順に時計周り
    if (dot(b, c) < 0) return +2;          // c--a--b 直線
    if (norm(b) < norm(c)) return -2;      // a--b--c 直線
    return 0;                              // a--c--b 直線
}

/* 与えら れた点集合の凸包をかえす.
 * psは3つ以上の要素を持たねばならない. */
bool operator<(const Point& a, const Point& b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
void convexHull(vector<Point> ps, vector<Point>& ans) {
    sort(ps.begin(), ps.end());
    int N = ps.size();
    int k = 0;
    ans.resize(N * 2);
    for (int i = 0; i < N; ans[k++] = ps[i++])
        while (k >= 2 && ccw(ans[k - 2], ans[k - 1], ps[i]) <= 0) k--;
    for (int i = N - 2, t = k + 1; i >= 0; ans[k++] = ps[i--])
        while (k >= t && ccw(ans[k - 2], ans[k - 1], ps[i]) <= 0) k--;
    /* 返上の点も頂点としたい場合は上4行を
     *     for (int i = 0; i < N; ans[k++] = ps[i++])
     *         while (k >= 2 && ccw(ans[k - 2], ans[k - 1], ps[i]) == -1) k--;
     *     for (int i = N - 2, t = k + 1; i >= 0; ans[k++] = ps[i--])
     *         while (k >= t && ccw(ans[k - 2], ans[k - 1], ps[i]) == -1) k--;
     * にする. */
    ans.resize(k - 1);
}

int main() {
    while (true) {
        int N; cin >> N;
        if (N == 0) break;
        vector<Point> ps(N);
        for (int i = 0; i < N; i++) {
            cin >> ps[i];
        }
        vector<Point> hull;
        convexHull(ps, hull);
        cout << N - hull.size() << endl;
    }
    return 0;
}