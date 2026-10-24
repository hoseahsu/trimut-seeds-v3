#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define first fi;
#define second se;
using namespace std;
typedef pair<int, int> P;

signed main(){
    int q;
    cin >> q;
    int p, n;
    char c;
    int now = 0;
    rep(i, 0, q){
        cin >> p >> c >> n;
        if(c == '(') now += n;
        else now -= n;
        if(now == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}