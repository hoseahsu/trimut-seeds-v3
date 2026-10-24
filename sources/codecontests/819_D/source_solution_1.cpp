#include <bits/stdc++.h>
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline bool repr(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool repl(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T gcd(T a, T b) {
  T t;
  if (a < b) {
    while (a) {
      t = a;
      a = b % a;
      b = t;
    }
    return b;
  } else {
    while (b) {
      t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
struct Cg {
  inline char operator()() { return getchar(); }
};
struct Cp {
  inline void operator()(char x) { putchar(x); }
};
inline bool IS(char x) { return x == 10 || x == 13 || x == ' '; }
template <typename T>
struct Fr {
  T P;
  inline Fr &operator,(int &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  inline operator int() {
    int x;
    *this, x;
    return x;
  }
  inline Fr &operator,(long long &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  inline operator long long() {
    long long x;
    *this, x;
    return x;
  }
  inline Fr &operator,(char &x) {
    for (x = P(); IS(x); x = P())
      ;
    return *this;
  }
  inline operator char() {
    char x;
    *this, x;
    return x;
  }
  inline Fr &operator,(char *x) {
    char t = P();
    for (; IS(t); t = P())
      ;
    if (~t) {
      for (; !IS(t) && ~t; t = P()) *x++ = t;
    }
    *x++ = 0;
    return *this;
  }
  inline Fr &operator,(double &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  inline operator double() {
    double x;
    *this, x;
    return x;
  }
  inline Fr &operator,(long double &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  inline operator long double() {
    long double x;
    *this, x;
    return x;
  }
  inline Fr &operator,(unsigned int &x) {
    x = 0;
    char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  inline operator unsigned int() {
    unsigned int x;
    *this, x;
    return x;
  }
  inline Fr &operator,(unsigned long long &x) {
    x = 0;
    char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  inline operator unsigned long long() {
    unsigned long long x;
    *this, x;
    return x;
  }
};
Fr<Cg> in;
template <typename T>
struct Fw {
  T P;
  inline Fw &operator,(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(unsigned int x) {
    if (x) {
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(unsigned int x) {
    if (x) {
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(unsigned long long x) {
    if (x) {
      char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(unsigned long long x) {
    if (x) {
      char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(char x) {
    P(x);
    return *this;
  }
  inline Fw &operator()(char x) {
    P(x);
    return *this;
  }
  inline Fw &operator,(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  inline Fw &operator()(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  inline Fw &operator()(double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
  inline Fw &operator()(long double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
};
Fw<Cp> out;
const int N = 200007;
inline void exgcd(long long a, long long b, long long &x, long long &y) {
  if (b)
    exgcd(b, a % b, y, x), y -= (a / b) * x;
  else
    x = 1, y = 0;
}
inline long long inv(long long a, long long b) {
  long long x, y;
  exgcd(b, a, y, x);
  return (x + b) % b;
}
long long n, ans[N];
long long m, sum, s[N];
std::map<long long, std::vector<std::pair<long long, long long> > > f;
int main() {
  in, m, n;
  for (int i = 1, iend = n; i <= iend; i++) in, s[i];
  for (int i = 1, iend = n; i <= iend; i++) sum += s[i];
  s[1] = 0;
  for (int i = 1, iend = n; i <= iend; i++) s[i] += s[i - 1];
  long long r = gcd(m, sum);
  for (int i = 1, iend = n; i <= iend; i++)
    f[s[i] % r].push_back(std::make_pair(i, s[i] / r));
  for (__typeof(f.end()) _a = f.begin(); _a != f.end(); ++_a) {
    std::vector<std::pair<long long, long long> > &g = _a->second;
    std::map<long long, std::pair<long long, long long> > t;
    long long x = m / r, v = (sum / r) % x, iv = inv(v, x);
    assert(gcd(v, x) == 1);
    for (__typeof(g.end()) i = g.begin(); i != g.end(); ++i) {
      long long u = i->second % x;
      if (t.find(u) == t.end() || i->second < t[u].second) t[u] = *i;
    }
    std::vector<std::pair<long long, long long> > tmp;
    for (__typeof(t.end()) i = t.begin(); i != t.end(); ++i) {
      long long p = i->second.first, q = i->first, tm;
      tm = (long long)iv * q % x;
      tmp.push_back(std::make_pair(tm, p));
    }
    std::sort(tmp.begin(), tmp.end());
    for (int i = 0, iend = tmp.size() - 1; i < iend; i++) {
      ans[tmp[i].second] = tmp[i + 1].first - tmp[i].first;
    }
    ans[tmp[tmp.size() - 1].second] =
        tmp[0].first + x - tmp[tmp.size() - 1].first;
  }
  for (int i = 1, iend = n; i <= iend; i++) out, ans[i], ' ';
  out, '\n';
}
