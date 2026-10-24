#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    ll mi = INF;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
        mi = min(mi, A[i]);
    }
    if(N % 2) {
        if(sum % 2) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    } else {
        if(sum % 2) { // sente
            if(mi % 2) {
                cout << "First" << endl;
            } else {
                cout << "First" << endl;
            }
        } else { // gote
            if(mi % 2) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}
