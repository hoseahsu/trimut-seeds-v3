#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define rint register int
#define rll register ll 
#define pii pair<int, int>
#define pll pair<ll, ll>
//#define p1 first
//#define p2 second
#define fors(i, a, b) for (register int i = (a); i <= (b); ++i)
#define _fors(i, a, b) for (ll i = (a); i >= (b); --i)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define mem(A, b) memset(A, b, sizeof(A))
#define all(X) (X).begin(), (X).end()
#define pb push_back

static struct FastInput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t chars_read = 0;
  size_t buf_pos = 0;
  FILE *in = stdin;
  char cur = 0;
 
  inline char get_char() {
    if (buf_pos >= chars_read) {
      chars_read = fread(buf, 1, BUF_SIZE, in);
      buf_pos = 0;
      buf[0] = (chars_read == 0 ? -1 : buf[0]);
    }
    return cur = buf[buf_pos++];
  }
 
  inline void tie(int) {}
 
  inline explicit operator bool() {
    return cur != -1;
  }
 
  inline static bool is_blank(char c) {
    return c <= ' ';
  }
 
  inline bool skip_blanks() {
    while (is_blank(cur) && cur != -1) {
      get_char();
    }
    return cur != -1;
  }
 
  inline FastInput& operator>>(char& c) {
    skip_blanks();
    c = cur;
    return *this;
  }
  
  inline FastInput& operator>>(string& s) {
    if (skip_blanks()) {
      s.clear();
      do {
        s += cur;
      } while (!is_blank(get_char()));
    }
    return *this;
  }
 
  template <typename T>
  inline FastInput& read_integer(T& n) {
    // unsafe, doesn't check that characters are actually digits
    n = 0;
    if (skip_blanks()) {
      int sign = +1;
      if (cur == '-') {
        sign = -1;
        get_char();
      }
      do {
        n += n + (n << 3) + cur - '0';
      } while (!is_blank(get_char()));
      n *= sign;
    }
    return *this;
  }
 
  template <typename T>
  inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
    return read_integer(n);
  }
  
  #if !defined(_WIN32) || defined(_WIN64)
  inline FastInput& operator>>(__int128& n) {
    return read_integer(n);
  }
  #endif
 
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
    // not sure if really fast, for compatibility only
    n = 0;
    if (skip_blanks()) {
      string s;
      (*this) >> s;
      sscanf(s.c_str(), "%lf", &n);
    }
    return *this;
  }
} fast_input;
 
#define cin fast_input
 
static struct FastOutput {
  static constexpr int BUF_SIZE = 1 << 20;
  char buf[BUF_SIZE];
  size_t buf_pos = 0;
  static constexpr int TMP_SIZE = 1 << 20;
  char tmp[TMP_SIZE];
  FILE *out = stdout;
 
  inline void put_char(char c) {
    buf[buf_pos++] = c;
    if (buf_pos == BUF_SIZE) {
      fwrite(buf, 1, buf_pos, out);
      buf_pos = 0;
    }
  }
 
  ~FastOutput() {
    fwrite(buf, 1, buf_pos, out);
  }
 
  inline FastOutput& operator<<(char c) {
    put_char(c);
    return *this;
  }
 
  inline FastOutput& operator<<(const char* s) {
    while (*s) {
      put_char(*s++);
    }
    return *this;
  }
 
  inline FastOutput& operator<<(const string& s) {
    for (int i = 0; i < (int) s.size(); i++) {
      put_char(s[i]);
    }
    return *this;
  }
 
  template <typename T>
  inline char* integer_to_string(T n) {
    // beware of TMP_SIZE
    char* p = tmp + TMP_SIZE - 1;
    if (n == 0) {
      *--p = '0';
    } else {
      bool is_negative = false;
      if (n < 0) {
        is_negative = true;
        n = -n;
      }
      while (n > 0) {
        *--p = (char) ('0' + n % 10);
        n /= 10;
      }
      if (is_negative) {
        *--p = '-';
      }
    }
    return p;
  }
 
  template <typename T>
  inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
    return integer_to_string(n);
  }
 
  #if !defined(_WIN32) || defined(_WIN64)
  inline char* stringify(__int128 n) {
    return integer_to_string(n);
  }
  #endif
 
  template <typename T>
  inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
    sprintf(tmp, "%.17f", n);
    return tmp;
  }
 
  template <typename T>
  inline FastOutput& operator<<(const T& n) {
    auto p = stringify(n);
    for (; *p != 0; p++) {
      put_char(*p);
    }
    return *this;
  }
} fast_output;

#define cout fast_output
#define endl '\n'

const int _ = 1e3 + 5;
const int mod = 998244353;
int a[_];
int m, n;

int qpow(int aa, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = 1LL * ret * aa % mod;
    aa = 1LL * aa * aa % mod;
    p >>= 1;
  }
  return ret;
}

signed main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int start_time = clock();
  /*
  int T;
  cin >> T;
  while (T--) {
    
  }*/
  cin >> m;
  fors(i, 1, m) cin >> a[i];
  sort(a + 1, a + m + 1);
  fors(i, 1, m) n += a[i];
  int ret = 0, f = 0, g = 1, b = 0, d = -1, t;
  fors(i, 1, m) {
    for (; b < a[i]; b++) {
      g = 1LL * g * (2 * n - b) % mod;
      f = 1LL * (n - b) * f % mod;
      f = (f + g) % mod;
      d = 1LL * d * (n - b) % mod;
    }
    t = 1LL * f * qpow(d, mod-2) % mod;
    ret = (ret + t) % mod;
    //cout << ret << endl;
  }
  for (; b < n; b++) {
    g = 1LL * g * (2 * n - b) % mod;
    f = 1LL * (n - b) * f % mod;
    f = (f + g) % mod;
    d = 1LL * d * (n - b) % mod;
  }
  t = 1LL * f * qpow(d, mod-2) % mod;
  ret = (ret - t) % mod;
  ret = (ret + mod) % mod;
  cout << ret << endl;
  //cout << "time = " << clock() - start_time << endl;
  return 0;
}