#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

#ifndef FENWICK
#define FENWICK

// Fenwick tree implementation to compute sum on subsegments.
// Each function requires O(log(N)).

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

// A structure able to perform the following operation on an array A:
// 1. Sum x to A[i].
// 2. Get the sum A[l] + A[l+1] + ... + A[r].
// Both the operation are O(log(N)).
// Everything is 0-based.
template <typename Value>
class Fenwick {
  public:
    // The Fenwick tree is initialized leaving all entries with the value 0.
    Fenwick(int N) :
        size(N),
        max_pow2(log2(N)),
        container(N, 0) {}

    // Initialize the Fenwick tree with the given values as entries.
    Fenwick(const vector<Value>& initial_values) :
            Fenwick(initial_values.size()) {
        for (int p = 0; p < size; p++) {
            int q = p | (p+1);
            container[p] += initial_values[p];
            if (q < size) container[q] += container[p];
        }
    }

    // Add x to the p-th entry.
    void Add(int p, Value x) {
        for (; p < size; p |= (p+1)) container[p] += x;
    }

    // Get the sum on the interval [l, r].
    Value GetRange(int l, int r) {
        if (l > 0) return GetRange(0, r) - GetRange(0, l-1);
        Value res = 0;
        for (; r >= 0; r = (r&(r+1))-1) res += container[r];
        return res;
    }

    // Get the value of the p-th entry.
    Value Get(int p) {
        return GetRange(p, p);
    }
    
    // Get the smallest p >= 0 such that GetRange(0, p) >= x.
    // If such a p does not exist, it returns size.
    // ACHTUNG: Works only if all values are nonnegative.
    int LowerBound(Value x) {
        Value sum = 0;
        int res = 0;
        for(int i = 1 << max_pow2; i > 0; i >>= 1) {
            if(res + i - 1 < size and sum + container[res + i - 1] < x) {
                sum += container[res + i - 1];
                res += i;
            }
        }
        return res;
    }

    // Set the p-th entry to x.
    void Set(int p, Value x) {
        Add(p, x - Get(p));
    }

    // Prints the current state of the Fenwick tree.
    void Debug() {
        cout << "Internal container representation (size = " << size << "):\n";
        for (int i = 0; i < size; i++) cout << container[i] << " ";
        cout << "\nValues of the entries:\n";
        for (int i = 0; i < size; i++) cout << Get(i) << " ";
        cout << "\n";
        cout.flush();
    }
    
  private:
    int size; // = container.size() (just to have a shorter name).
    int max_pow2; // = maximum integer such that (1 << max_pow2) <= N.
    // container[xxx01...1] contains the sum of all the entries from
    // xxx00...0 to xxx01...1 inclusive.
    // i.e. container[2] contains exactly the value of entry[2], whereas
    // container[3] contains the sum entry[0] + entry[1] + entry[2] + entry[3].
    vector<Value> container;
};

#endif  // FENWICK
        
// Overloading of the operator << for __int128 type.
ostream& operator <<(ostream& out, __int128 x) {
    static short int digits[41];
    if (x == 0) {
        out << '0';
        return out;
    }
    if (x < 0) {
        out << '-';
        x = -x;
    }
    int length = 0;
    for (; x > 0; x /= 10) {
        digits[length] = x % 10;
        length++;
    }
    for (int i = length - 1; i >= 0; i--) out << digits[i];
    return out;
}


// Computes the inverse of n modulo m.
// Precondition: n >= 0, m > 0 and gcd(n, m) == 1.
// The returned value satisfies 0 <= x < m (Inverse(0, 1) = 0).
// ACHTUNG: It must hold max(m, n) < 2**31 to avoid integer overflow.
LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}

// Fast exponentiation modulo mod. Returns x**e modulo mod.
// Assumptions: 0 <= x < mod
//              mod < 2**31.
//              0 <= e < 2**63
LL pow(LL x, LL e, LL mod) {
    LL res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

// Struct that computes x % mod faster than usual, if mod is always the same.
// It gives a x1.8 speed up over the % operator (with mod ~ 1e9 and x large).
// It is an implementation of the Barrett reduction, see
//    https://en.wikipedia.org/wiki/Barrett_reduction .
// If fast_mod is an instance of the class, then fast_mod(x) will return
// x % mod. There are no restrictions on the values of mod and x, provided
// that they fit in an unsigned long long (and mod != 0).
//
// ACHTUNG: The integer type __uint128_t must be available.
struct FastMod {
    ULL mod;
    ULL inv;
    FastMod(ULL mod) : mod(mod), inv(-1ULL / mod) {}
    ULL operator()(ULL x) {
        ULL q = (ULL)((__uint128_t(inv) * x) >> 64);
        ULL r = x - q * mod;
        return r - mod * (r >= mod);
    }
};

// Class for integers modulo mod.
// It supports all expected operations: +, -, *, /, pow, ==, < and >.
// It is as fast as it can be.
// The modulo mod shall be set through set_mod().
//
// Assumptions: mod < (1<<30).
// ACHTUNG: The integer type __uint128_t must be available.
//
// Remark: To handle larger moduli (up to 1<<62), one has to:
//          1. replace int in the definitions of mod, n.
//          2. The parameter of fast_mod must be __uint128_t, so it must be
//             changed in the definition of fast_mod and in the definition of
//             the operators * and *=.
//          3. fast_mod must be a naive modulo operation, no barrett reduction.
//          4. In Inverse, __int128_t shall be used.
struct ModularInteger {
    static int mod;
    static __uint128_t inv_mod; // Necessary for fast_mod.
    int n; // 0 <= n < mod at all times
    static void set_mod(int _mod) {
        mod = _mod;
        inv_mod = -1ULL / mod;
    }
    ModularInteger(): n(0) {}
    ModularInteger(LL _n): n(_n % mod) {
        n += (n<0)*mod;
    }
    LL get() const { return n; }
    static int fast_mod(ULL x) { // Barrett reduction.
        ULL q = (inv_mod * x) >> 64;
        int m = x - q * mod;
        m -= mod * (m >= mod);
        return m;
    }

    ModularInteger operator-() const { return n?mod-n:0; }
};
int ModularInteger::mod;
__uint128_t ModularInteger::inv_mod;

ModularInteger operator +(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n + B.n;
    C.n -= (C.n >= ModularInteger::mod)*ModularInteger::mod;
    return C;
}

void operator +=(ModularInteger& A, const ModularInteger& B) {
    A.n += B.n;
    A.n -= (A.n >= ModularInteger::mod)*ModularInteger::mod;
}

ModularInteger operator -(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = A.n - B.n;
    C.n += (C.n < 0)*ModularInteger::mod;
    return C;
}

void operator -=(ModularInteger& A, const ModularInteger& B) {
    A.n -= B.n;
    A.n += (A.n < 0)*ModularInteger::mod;
}

ModularInteger operator *(const ModularInteger& A, const ModularInteger& B) {
    ModularInteger C;
    C.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
    return C;
}

void operator *=(ModularInteger& A, const ModularInteger& B) {
    A.n = ModularInteger::fast_mod(((ULL)A.n) * B.n);
}

// Assumption: gcd(B, mod) = 1.
ModularInteger operator /(const ModularInteger& A, const ModularInteger& B) {
    return A * Inverse(B.n, ModularInteger::mod);
}

// Assumption: gcd(B, mod) = 1.
void operator/=(ModularInteger& A, const ModularInteger& B) {
    A *= Inverse(B.n, ModularInteger::mod);
}

ModularInteger power(ModularInteger A, ULL e) {
    ModularInteger res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res *= A;
        A *= A;
    }
    return res;
}

bool operator ==(const ModularInteger& A, const ModularInteger& B) {
    return A.n == B.n;
}
bool operator !=(const ModularInteger& A, const ModularInteger& B) {
    return A.n != B.n;
}
bool operator <(const ModularInteger& A, const ModularInteger& B) {
    return A.n < B.n;
}
bool operator >(const ModularInteger& A, const ModularInteger& B) {
    return A.n > B.n;
}
bool operator <=(const ModularInteger& A, const ModularInteger& B) {
    return A.n <= B.n;
}
bool operator >=(const ModularInteger& A, const ModularInteger& B) {
    return A.n >= B.n;
}

ostream& operator <<(ostream& out, const ModularInteger& A) {
    out << A.n;
    return out;
}

istream& operator >>(istream& in, ModularInteger& A) {
  LL a;
  in >> a;
  A = ModularInteger(a);
  return in;
}

typedef ModularInteger mint;

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    mint::set_mod(998244353);

    int N, K;
    cin >> N >> K;

    Fenwick<mint> fen1(N+1), fen2(N+1), fen3(N+1);

    vector<int> p(N+1);
    vector<int> invp(N+1);
    for (int i = 1; i <= N; i++) cin >> p[i], invp[p[i]] = i;
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++) a[i] = max(K, i);

    mint z = mint(K-1)/K;
    mint invz = 1/z;
    for (int i = 1; i <= N; i++) fen1.Set(i, power(z, a[i]));

    mint res = 0;
    for (int pp = 1; pp <= N; pp++) {
        int i = invp[pp];
        fen1.Set(i, 0);

        res += power(invz, a[i]) * (fen1.GetRange(i, N) - fen2.GetRange(i, N)) / 2;
        res += fen3.GetRange(i, N);
        
        fen2.Set(i, power(z, a[i]));
        fen3.Set(i, 1);
    }
    cout << res << "\n";
}
