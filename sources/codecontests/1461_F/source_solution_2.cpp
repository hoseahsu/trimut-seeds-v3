#include <bits/stdc++.h>
using namespace std;

int n;
char c;
vector<int> a, prv;
vector<char> s;
vector<int64_t> dp;
unordered_set<char> symbol;

void solve(int l, int r) {
    // solve without 0s
    // skip 1s in the beginning and the end
    while (l < r && a[l] == 1)
        s[l++] = '+';
    while (l < r && a[r] == 1)
        s[--r] = '+';
    if (l == r) return;
    // if the product > n we multiply all
    int64_t prod = 1;
    for (int i = l; i <= r; i++) {
        prod *= a[i];
        if (prod > n) {
            for (int j = l; j < r; j++) 
                s[j] = '*';
            return;
        }
    }
    // DP to solve the middle
    for (int i = l; i <= r; i++) {
        if (a[i] == 1) {
            dp[i] = (i > 0 ? dp[i - 1] : 0) + 1;
            prv[i] = i - 1;
            continue;
        }
        prod = 1;
        for (int j = i; j >= l; j--) {
            prod *= a[j];
            int64_t previous = (j > 0 ? dp[j - 1] : 0);
            if (prod + previous > dp[i]) {
                dp[i] = prod + previous;
                prv[i] = j - 1;
            }
        }
    }
    for (int i = r; i > l; i = prv[i]) {
        for (int j = i - 1; j > prv[i]; j--) s[j] = '*';
        s[prv[i]] = '+';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    a.assign(n, 1);
    for (int& it : a) 
        cin >> it;
    while (cin >> c) 
        symbol.insert(c);

    if (int(symbol.size()) == 1) {
        // "+" or "-" or "*"
        s.assign(n, *symbol.begin());
        s.back() = '\n';
    } else if (!symbol.count('*')) {
        // "+-"
        s.assign(n, '+');
        s.back() = '\n';
    } else if (!symbol.count('+')) {
        // "-*"
        s.assign(n, '*');
        s.back() = '\n';
        for (int i = 1; i < n; i++) {
            if (a[i] == 0){
                s[i - 1] = '-';
                break;
            }
        }
    } else {
        // "+*" or "+-*"
        s.assign(n, '\n');
        dp.assign(n, 0LL);
        prv.assign(n, -1);
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (i > 0) s[i - 1] = '+';
                if (i < n - 1) s[i] = '+';
                if (l < i) solve(l, i - 1);
                l = i + 1;
            }
        }
        if (l < n)
            solve(l, n - 1);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << s[i];
    return 0;
}