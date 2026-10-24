#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length()+1; i += 2) {
        if (s[i] == 'L' || s[i+1] == 'R') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}