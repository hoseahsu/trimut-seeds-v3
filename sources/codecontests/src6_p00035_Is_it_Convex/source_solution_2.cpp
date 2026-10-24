#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;

constexpr double eps = 1e-8;

double dot(point a, point b) {
    return real(conj(a) * b);
}
double cross(point a, point b) {
    return imag(conj(a) * b);
}

int ccw(point a, point b, point c) {
    b -= a, c -= a;
    if(cross(b, c) > eps) return 1;
    if(cross(b, c) < -eps) return -1;
    if(dot(b, c) < 0) return 2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

bool isis_ss(point a1, point b1, point a2, point b2) {
    return ccw(a1, b1, a2) * ccw(a1, b1, b2) <= 0 && ccw(a2, b2, a1) * ccw(a2, b2, b1) <= 0;
}

int main() {
    string s;
    while(cin >> s) {
        for(auto& c : s) if(c == ',') c = ' ';
        stringstream ss(s);
        vector<point> ps;
        for(int i = 0; i < 4; ++i) {
            double x, y; ss >> x >> y;
            ps.emplace_back(x, y);
        }

        bool ok = true;
        for(int i = 0; i < 4; ++i) {
            ok &= isis_ss(ps[i], ps[(i + 2) % 4], ps[(i + 1) % 4], ps[(i + 3) % 4]);
        }
        
        cout << (ok ? "YES" : "NO") << endl;
    }
}
