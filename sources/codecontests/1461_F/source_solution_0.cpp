#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <chrono>
#include <random>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <tuple>
#include <list>
#include <set>
#include <map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define add push_back
#define m_p make_pair
#define m_t make_tuple
#define fr first
#define sc second
#define endl '\n'
#define print std::ostream_iterator<ll>(std::cout, " ")
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<ll, ll> pii;
const ll N = 100005, mod = 1000000007, M = 505;
const ll inf = 1000000000000000000;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, k, i, j, kaskad[N], dp[N];
string ans;
ll x, sum, t;
int ind;
void solve(int left, int right) {
    if (left == right) return;
    while (left < right && kaskad[left] == 1) {
        if (left < n - 1) ans[left] = '+';
        left++;
    }
    right--;
    while (right >= left && kaskad[right] == 1) {
        if (right >= 1) ans[right - 1] = '+';
        right--;
    }
    right++;
    if (left >= right) return;
    t = 1;
    for (int i = left; i < right; ++i) {
        t *= kaskad[i];
        if (t > mod) t = mod;
    }
    if (t == mod) return;
    vector<ll> vec;
 
    for (int i = left; i < right; ++i) {
        if (kaskad[i] > 1) {
            if (vec.size() % 2 == 0) {
                vec.add(kaskad[i]);
                continue;
            }
            vec.back() *= kaskad[i];
            continue;
        }
        if (vec.size() % 2 == 1) {
            vec.add(1);
            continue;
        }
        vec.back()++;
    }
 
    vector<ll> dp((vec.size() + 1) / 2, -1);
    vector<string> ch((vec.size() + 1) / 2);
    dp[0] = vec[0];
    for (int i = 2; i < vec.size(); i += 2) {
        x = 1;
        ind = i;
        for (int j = i; j >= 0; j -= 2) {
            x *= vec[j];
            sum = x;
            if (j > 0) sum += dp[(j - 2) / 2] + vec[j - 1];
            if (sum > dp[i/2]) {
                ind = j;
                dp[i / 2] = sum;
            }
        }
        ch[i / 2] = "";
        if (ind > 0) {
            ch[i / 2] += ch[(ind - 2) / 2];
            ch[i / 2] += '+';
        }
        ch[i / 2] += string((i - ind) / 2, '*');
    }
    ind = 0;
    for (int i = left; i < right; ++i) {
        if (kaskad[i] == 1) {
            while (i < right && kaskad[i] == 1) {
                if (i > 0) ans[i - 1] = ch.back()[ind];
                if (i < n - 1) ans[i] = ch.back()[ind];
                ++i;
            }
            ind++;
        }
    }
}
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ans = string(n - 1, '*');
    for (int i = 0; i < n; ++i) {
        cin >> kaskad[i];
    }
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    // *+-
    if (s[0] == '+') {
        s = "+";
    }
    if (s.size() == 1 || n == 1) {
        cout << kaskad[0];
        for (int i = 1; i < n; ++i) {
            cout << s[0] << kaskad[i];
        }
        cout << endl;
        return 0;
    }
    if (s.size() == 3) {
        s = "*+";
    }
    if (s == "*-") {
        cout << kaskad[0];
        bool flag = (kaskad[0] == 0);
        for (int i = 1; i < n; ++i) {
            if (flag) {
                cout << '*' << kaskad[i];
                continue;
            }
            if (kaskad[i] == 0) {
                flag = true;
                cout << '-';
            }
            else {
                cout << '*';
            }
            cout << kaskad[i];
        }
        cout << endl;
        return 0;
    }
    vector<int> zeros{ -1 };
    for (int i = 0; i < n; ++i) {
        if (kaskad[i] == 0) {
            if (i - 1 >= 0) ans[i - 1] = '+';
            if (i < n - 1) ans[i] = '+';
            zeros.add(i);
        }
    }
    zeros.add(n);
    for (int i = 0; i < zeros.size() - 1; ++i) {
        solve(zeros[i] + 1, zeros[i + 1]);
    }
 
    cout << kaskad[0];
    for (int i = 1; i < n; ++i) {
        cout << ans[i - 1] << kaskad[i];
    }
    cout << endl;
    cout << endl;
}