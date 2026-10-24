#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define repd(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    
    ll N, D;
    cin >> N >> D;
    if(D == 1) {
        cout << N * (N - 1) / 2 << endl;
    }
    else if(D == 2){
        cout << N * (N - 1) / 2 - 1 << endl;
    }
    else{
        ll A = N - (D - 2);
        cout << A * (A - 1) / 2 - 1 + D - 2 << endl;
    }
    
    
    return 0;
}