#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
    string s;
    while (cin >> s >> s) {
        auto p = s.find("xx");
        int n = s.size();
        if (p == string::npos) {
            cout << n;
        } else {
            cout << p + 1;
        }
        cout << endl;
    }
}