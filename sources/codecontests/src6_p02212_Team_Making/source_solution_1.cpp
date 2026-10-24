#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
int main() {
    int A[4];
    for (auto &a : A) cin >> a;
    sort(begin(A), end(A));
    int ans = 1e9;
    do {
        int t = abs(A[0] + A[1] - A[2] - A[3]);
        ans = min(ans, t);
    } while (next_permutation(begin(A), end(A)));
    cout << ans << endl;
    return 0;
}
