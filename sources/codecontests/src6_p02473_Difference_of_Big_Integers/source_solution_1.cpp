// includes
#include <bits/stdc++.h>

// macros
#define ll long long int
#define pb emplace_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(st, itr) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define vrep(v, i) for(int i = 0; i < (v).size(); i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define FI first
#define SE second
#define dump(a, n) for(int i = 0; i < n; i++)cout << a[i] << "\n "[i + 1 != n];
#define dump2(a, n, m) for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cout << a[i][j] << "\n "[j + 1 != m];
using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}

const ll B = 10000;
const int BW = 4;
struct BigInt{
  vector<ll> digit;
  BigInt(ll a = 0){
    digit.emplace_back(a);
    normalize();
  }
  BigInt(const string &s){
    from_string(s);
  }
  void from_string(const string &s){
    digit.clear();
    int i;
    for(i = (int)s.size() - BW; i >= 0; i-=BW){
      digit.emplace_back(stol(s.substr(i, BW)));
    }
    i += BW;
    if(i > 0)digit.emplace_back(stol(s.substr(0, i)));
  }
  void normalize(){
    ll c = 0;
    for(int i = 0; i < digit.size(); i++){
      while(digit[i] < 0){
        if(i + 1 == digit.size())digit.emplace_back(0);
        digit[i+1]--;
        digit[i] += B;
      }
      ll a = digit[i] + c;
      digit[i] = a % B;
      c = a / B;
    }
    while(c){
      digit.emplace_back(c % B);
      c /= B;
    }
    for(int i = (int)digit.size() - 1; i >= 1; i--){
      if(digit[i] == 0){
        digit.pop_back();
      }else{
        break;
      }
    }
  }
  size_t size(){
    return digit.size();
  }
  BigInt& operator=(ll a){
    digit.resize(1, a);
    normalize();
    return *this;
  }
  BigInt& operator=(const string &s){
    from_string(s);
    return *this;
  }
} ZERO(0), ONE(1);

ostream &operator<<(ostream &os, const BigInt &b){
  os << b.digit[b.digit.size() - 1];
  for(int i = (int)b.digit.size() - 2; i >= 0; i--){
    os << setw(BW) << setfill('0') << b.digit[i];
  }
  return os;
}

istream & operator>>(istream &is, BigInt &b){
  string s;
  is >> s;
  b.from_string(s);
  return is;
}

bool operator<(const BigInt &x, const BigInt &y){
  if(x.digit.size() != y.digit.size())return x.digit.size() < y.digit.size();
  for(int i = x.digit.size() - 1; i >= 0; i--){
    if(x.digit[i] != y.digit[i])return x.digit[i] < y.digit[i];
  }
  return false;
}

bool operator>(const BigInt &x, const BigInt y){
  return y < x;
}

bool operator<=(const BigInt &x, const BigInt &y){
  return !(y < x);
}

bool operator>=(const BigInt &x, const BigInt &y){
  return !(x < y);
}

bool operator!=(const BigInt &x, const BigInt &y){
  return x < y || y < x;
}

bool operator==(const BigInt &x, const BigInt &y){
  return !(x < y) && !(y < x);
}

BigInt operator+(const BigInt &x, ll a){
  BigInt res = x;
  res.digit[0] += a;
  res.normalize();
  return res;
}

BigInt operator+(const BigInt &x, const BigInt &y){
  BigInt res = x;
  while(res.digit.size() < y.digit.size())res.digit.emplace_back(0);
  for(int i = 0; i < y.digit.size(); i++)res.digit[i] += y.digit[i];
  res.normalize();
  return res;
}

BigInt operator-(const BigInt &x, const BigInt &y){
  BigInt res = x;
  assert(res.digit.size() >= y.digit.size());
  for(int i = 0; i < y.digit.size(); i++)res.digit[i] -= y.digit[i];
  res.normalize();
  return res;
}

BigInt operator*(const BigInt &x, const BigInt &y){
  BigInt z;
  z.digit.assign(x.digit.size() + y.digit.size(), 0);
  for(int i = 0; i < x.digit.size(); i++){
    for(int j = 0; j < y.digit.size(); j++){
      z.digit[i+j] += x.digit[i] * y.digit[j];
    }
  }
  z.normalize();
  return z;
}

BigInt operator*(const BigInt &x, ll a){
  BigInt res = x;
  for(int i = 0; i < res.digit.size(); i++)res.digit[i] *= a;
  res.normalize();
  return res;
}

pair<BigInt, ll> divmod(const BigInt &x, ll a){
  ll c = 0;
  BigInt res = x;
  for(int i = (int)res.digit.size() - 1; i >= 0; i--){
    ll t = B * c + res.digit[i];
    res.digit[i] = t / a;
    c = t % a;
  }
  res.normalize();
  return make_pair(res, c);
}

BigInt operator/(const BigInt &x, ll a){
  return divmod(x, a).first;
}

BigInt operator%(const BigInt &x, ll a){
  return divmod(x, a).second;
}

pair<BigInt, BigInt> divmod(const BigInt &x, const BigInt &y){
  BigInt rx = x, ry = y;
  if(x.digit.size() < y.digit.size())return make_pair(ZERO, x);
  int F = B / (y.digit[y.digit.size() - 1] + 1);
  rx = rx * F; ry = ry * F;
  BigInt z;
  z.digit.assign(rx.digit.size() - ry.digit.size() + 1, 0);
  for(int k = (int)z.digit.size() - 1, i = (int)rx.digit.size() - 1; k >= 0; k--, i--){
    z.digit[k] = (i + 1 < rx.digit.size() ? rx.digit[i+1]: 0) * B + rx.digit[i];
    z.digit[k] /= ry.digit[ry.digit.size() - 1];
    BigInt t;
    t.digit.assign(k + ry.digit.size(), 0);
    for(int m = 0; m < ry.digit.size(); m++){
      t.digit[k+m] = z.digit[k] * ry.digit[m];
    }
    t.normalize();
    while(rx < t){
      z.digit[k] -= 1;
      for(int m = 0; m < ry.digit.size(); m++){
        t.digit[k+m] -= ry.digit[m];
      }
      t.normalize();
    }
    rx = rx - t;
  }
  z.normalize();
  return make_pair(z, rx / F);
}

BigInt operator/(const BigInt &x, const BigInt &y){
  return divmod(x, y).first;
}

BigInt operator%(const BigInt &x, const BigInt &y){
  return divmod(x, y).second;
}

BigInt& operator+=(BigInt &x, ll a){
  x = x + a;
  return x;
}

BigInt &operator+=(BigInt &x, const BigInt &y){
  x = x + y;
  return x;
}

BigInt &operator-=(BigInt &x, const BigInt &y){
  x = x - y;
  return x;
}

BigInt& operator*=(BigInt &x, const BigInt &y){
  x = x * y;
  return x;
}

BigInt& operator/=(BigInt &x, const BigInt &y){
  x = x / y;
  return x;
}

BigInt& operator%=(BigInt &x, const BigInt &y){
  x = x % y;
  return x;
}

BigInt& operator/=(BigInt &x, ll a){
  x = x / a;
  return x;
}

BigInt& operator%=(BigInt &x, ll a){
  x = x % a;
  return x;
}

BigInt sqrt(const BigInt &x){
  BigInt l = 1;
  BigInt r = x;
  while(r - l > BigInt(1)){
    BigInt m = (r + l) / 2;
    if(m * m > x)r = m;
    else l = m;
  }
  return l;
}

struct SBigInt{
  bool neg = false;
  BigInt b = 0;
  SBigInt(){}
  SBigInt(ll a): b(BigInt(abs(a))){
    if(a < 0)neg = true;
  }
  SBigInt(const string &s){
    string t = s;
    if(t[0] == '-'){
      neg = true;
      t = t.substr(1, t.size() - 1);
    }
    b = BigInt(t);
  }
  void check_zero(){
    if(b == ZERO)neg = false;
  }
  bool operator==(const SBigInt &r) const{
    return (neg == r.neg) && (b == r.b);
  }
  bool operator!=(const SBigInt &r) const{
    return (neg != r.neg) || (b != r.b);
  }
  SBigInt operator-() const{
    SBigInt res = *this;
    res.neg = !res.neg;
    res.check_zero();
    return res;
  }
};

SBigInt operator+(const SBigInt &x, const SBigInt &y){
  SBigInt res;
  if(x.neg == y.neg){
    res.b = x.b + y.b;
    res.neg = x.neg;
  }else{
    if(x.b > y.b){
      res.b = x.b - y.b;
      res.neg = x.neg;
    }else{
      res.b = y.b - x.b;
      res.neg = y.neg;
    }
  }
  res.check_zero();
  return res;
}

SBigInt operator-(const SBigInt &x, const SBigInt &y){
  SBigInt res = x + (- y);
  res.check_zero();
  return res;
}

SBigInt operator*(const SBigInt &x, const SBigInt &y){
  SBigInt res;
  res.neg = !(x.neg == y.neg);
  res.b = x.b * y.b;
  res.check_zero();
  return res;
}

SBigInt operator/(const SBigInt &x, const SBigInt &y){
  SBigInt res;
  res.neg = !(x.neg == y.neg);
  res.b = x.b / y.b;
  res.check_zero();
  return res;
}

ostream &operator<<(ostream &os, const SBigInt &b){
  if(b.neg)os << "-";
  os << b.b;
  return os;
}

int main(int argc, char const* argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  SBigInt A(a), B(b);
  cout << A - B << endl;
  return 0;
}

