#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.X << ", " << pair.Y << ")";
}
int mod3(int a) {
  a = a % 3;
  if (a < 0) {
    a += 3;
  }
  return a;
}
long long det3(const vector<vector<long long> >& vec) {
  long long res = 0;
  for (int sign = -1; sign <= 1; sign += 2) {
    for (int i = 0; i < 3; i++) {
      res += sign * vec[0][i] * vec[1][mod3(i + sign)] *
             vec[2][mod3(i + 2 * sign)];
    }
  }
  return res;
}
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
struct p {
  vector<long long> coords;
  p(vector<long long>& c) { coords = c; }
  p() {}
  p operator-(const p& d) const {
    auto tmp = coords;
    while (coords.size() != 3 && d.coords.size() != 3)
      ;
    for (int i = 0; i < (3); ++i) {
      tmp[i] -= d.coords[i];
    }
    p to_ret = p(tmp);
    return to_ret;
  }
};
void normalize(vector<long long>& c) {
  bool zeros = true;
  long long maxgcd = 0;
  for (int i = 0; i < c.size(); i++) {
    maxgcd = gcd(maxgcd, c[i]);
  }
  if (maxgcd == 0) {
    throw 1;
  }
  for (long long& a : c) {
    a /= maxgcd;
  }
  bool negate = false;
  for (long long& a : c) {
    if (zeros && a < 0) {
      negate = true;
    }
    if (negate) {
      a *= -1;
    }
    zeros &= (a == 0);
  }
}
struct plane {
  vector<long long> coefs;

 private:
  void make_plane(vector<long long>& c) {
    normalize(c);
    coefs = c;
  }

 public:
  plane(const p& p1, const p& p2, const p& p3) {
    p tab[] = {p1, p2, p3};
    vector<vector<long long> > basic;
    for (int i = 0; i < (3); ++i) {
      basic.push_back(tab[i].coords);
    }
    vector<long long> c;
    c.resize(4);
    long long D = det3(basic);
    c[3] = D;
    for (int i = 0; i < (3); ++i) {
      auto tmp = basic;
      for (int j = 0; j < (3); ++j) {
        tmp[j][i] = 1;
      }
      c[i] = det3(tmp);
    }
    make_plane(c);
  }
  bool check(p pkt) {
    long long acc = 0;
    for (int i = 0; i < (3); ++i) {
      acc += pkt.coords[i] * coefs[i];
    }
    return acc == coefs[3];
  }
  plane() {}
};
vector<long long> convert(const p& p1, const p& p2) {
  p p3 = p1 - p2;
  normalize(p3.coords);
  return p3.coords;
}
vector<pair<long long, long long> > lines_intersection(const p& p1, const p& p2,
                                                       const p& p3,
                                                       const p& p4) {
  vector<vector<long long> > mat;
  mat.resize(3);
  mat[2].resize(3);
  p tab[] = {p1, p2};
  long long res[] = {0, 0};
  for (int j = 0; j < (3); ++j) {
    for (int i = 0; i < (2); ++i) {
      mat[0] = (p3 - tab[i]).coords;
      mat[1] = (p4 - tab[i]).coords;
      for (int k = 0; k < (3); ++k) {
        mat[2][k] = (j == k);
      }
      res[i] = det3(mat);
    }
    if (res[0] != 0 || res[1] != 0) {
      break;
    }
  }
  if (res[0] == 0 && res[1] == 0) {
    throw -1;
  }
  if (res[0] == res[1]) {
    throw -2;
  }
  vector<pair<long long, long long> > to_ret;
  for (int i = 0; i < (3); ++i) {
    pair<long long, long long> frac = make_pair(
        res[0] * p2.coords[i] - res[1] * p1.coords[i], res[0] - res[1]);
    long long gcd_ = gcd(frac.first, frac.second);
    frac.first /= gcd_;
    frac.second /= gcd_;
    to_ret.push_back(frac);
  }
  return to_ret;
}
map<vector<long long>, set<vector<long long> > > mapka;
map<vector<pair<long long, long long> >, set<int> > intersections;
const int N = 1005;
p mets[N][2];
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  ;
  for (int i = (1); i <= (n); ++i) {
    for (int j = 0; j < (2); ++j) {
      vector<long long> c;
      for (int k = (1); k <= (3); ++k) {
        int d;
        cin >> d;
        ;
        c.push_back(d);
      }
      mets[i][j] = p(c);
    }
  }
  int res = 1;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (i + 1); j <= (n); ++j) {
      plane tmp;
      try {
        tmp = plane(mets[i][0], mets[i][1], mets[j][0]);
      } catch (...) {
        tmp = plane(mets[i][0], mets[i][1], mets[j][1]);
      }
      if (!tmp.check(mets[j][1])) {
        continue;
      }
      try {
        vector<pair<long long, long long> > inter =
            lines_intersection(mets[i][0], mets[i][1], mets[j][0], mets[j][1]);
        auto& secik2 = intersections[inter];
        secik2.insert(i);
        secik2.insert(j);
        maxi(res, int(secik2.size()));
      } catch (...) {
      }
      set<vector<long long> >& secik = mapka[tmp.coefs];
      secik.insert(convert(mets[i][0], mets[i][1]));
      secik.insert(convert(mets[j][0], mets[j][1]));
      maxi(res, int(secik.size()));
    }
  }
  cout << res << endl;
  return 0;
}
