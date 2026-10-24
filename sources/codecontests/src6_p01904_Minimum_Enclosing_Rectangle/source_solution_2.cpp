#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

class Point
{
public:
    int y, x;
    Point(){
        y = x = 0;
    }
    Point(int y0, int x0){
        y = y0;
        x = x0;
    }
    Point operator+(const Point& p) const{
        return Point(y + p.y, x + p.x);
    }
    Point operator-(const Point& p) const{
        return Point(y - p.y, x - p.x);
    }
    Point operator*(int a) const{
        return Point(y * a, x * a);
    }
    bool operator==(const Point& p) const{
        return y == p.y && x == p.x;
    }
    bool operator<(const Point& p) const{
        return make_pair(y, x) < make_pair(p.y, p.x);
    }
    long long length2() const{
        return y * (long long)y + x * (long long)x;
    }
    long long dist2(const Point& p) const{
        return (y - p.y) * (long long)(y - p.y) + (x - p.x) * (long long)(x - p.x);
    }
    long long dot(const Point& p) const{
        return y * (long long)p.y + x * (long long)p.x; // |a|*|b|*cos??
    }
    long long cross(const Point& p) const{
        return x * (long long)p.y - y * (long long)p.x; // |a|*|b|*sin??
    }
};

void convexHull(const vector<Point>& p0, vector<Point>& ch)
{
    class Compare{
    public:
        bool operator()(const Point& a, const Point& b){
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        }
    };

    vector<Point> p = p0;
    sort(p.begin(), p.end(), Compare());
    int n = p.size();

    int j = 0;
    ch.clear();
    for(int i=0; i<2*n-1; ++i){
        Point tmp = (i<n? p[i]:p[2*(n-1)-i]);
        while(j >= 2 && (tmp-ch[j-2]).cross(ch[j-1]-ch[j-2]) <= 0){
            ch.pop_back();
            -- j;
        }
        ch.push_back(tmp);
        ++ j;
    }
    ch.pop_back();
}

const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};

int main()
{
    int n;
    cin >> n;
    vector<int> y(n), x(n);
    for(int i=1; i<n; ++i){
        int a, d;
        cin >> a >> d;
        y[i] = y[a] + dy[d];
        x[i] = x[a] + dx[d];
    }

    set<Point> s;
    for(int i=0; i<n; ++i){
        for(int j=0; j<4; ++j){
            int y2 = y[i] + j / 2;
            int x2 = x[i] + j % 2;
            s.insert(Point(y2, x2));
        }
    }
    vector<Point> ch;
    convexHull(vector<Point>(s.begin(), s.end()), ch);

    int m = ch.size();
    double ans = DBL_MAX;
    for(int i=0; i<m; ++i){
        Point d = ch[(i+1)%m] - ch[i];
        double theta = atan2((double)d.y, (double)d.x);

        double yMin = DBL_MAX;
        double yMax = -DBL_MAX;
        double xMin = DBL_MAX;
        double xMax = -DBL_MAX;
        for(int j=0; j<m; ++j){
            double y2 = ch[j].x * sin(-theta) + ch[j].y * cos(-theta);
            double x2 = ch[j].x * cos(-theta) - ch[j].y * sin(-theta);
            yMin = min(yMin, y2);
            yMax = max(yMax, y2);
            xMin = min(xMin, x2);
            xMax = max(xMax, x2);
        }
        ans = min(ans, (yMax - yMin) * (xMax - xMin));
    }
    printf("%.10f\n", ans);

    return 0;
}