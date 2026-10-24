#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
#define FOR(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define eFOR(i,a,n) for(int (i)=(a);(i)<=(n);(i)++)
#define rFOR(i,a,n) for(int (i)=(n)-1;(i)>=(a);(i)--)
#define erFOR(i,a,n) for(int (i)=(n);(i)>=(a);(i)--)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i,a) sort((i).begin(),(i).end(),(a))
#define all(i) (i).begin(),(i).end()
constexpr ll INF = 1000000000;
constexpr ll LLINF = 1LL << 60;
constexpr ll mod = 1000000007;
constexpr ll MOD = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; }return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; }return 0; }
inline void init() { cin.tie(nullptr); cout.tie(nullptr); cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); }
template<class T>inline istream& operator>>(istream& input, vector<T>& v) { for (auto& elemnt : v)input >> elemnt; return input; }

int main() {
    init();

    int n;
    cin >> n;
    string s;
    cin >> s;

    VI a(4, 0);
    for (char c : s) {
        if (c < 'N')a[0]++;
        else if (c < 'a')a[1]++;
        else if (c < 'n')a[2]++;
        else a[3]++;
    }
    if (a[0] < a[1]) {
        a[1] -= a[0];
        a[0] = 0;
    }
    else {
        a[0] -= a[1];
        a[1] = 0;
    }
    if (a[2] < a[3]) {
        a[3] -= a[2];
        a[2] = 0;
    }
    else {
        a[2] -= a[3];
        a[3] = 0;
    }

    string d = "ANan";
    int sum = 0;
    FOR(i, 0, 4)sum += a[i];
    cout << sum << "\n";
    FOR(i, 0, 4)FOR(j, 0, a[i])cout << d[i];
    cout << "\n";
}

