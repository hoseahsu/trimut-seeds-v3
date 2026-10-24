#include "bits/stdc++.h"
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '.') cnt2++;
    }

    int ans = cnt2;
    for (int i = 0; i < N; i++) {
        if (S[i] == '#') cnt1++;
        else cnt2--;
        ans = min(ans, cnt1 + cnt2);
    }
    cout << ans << endl;
}