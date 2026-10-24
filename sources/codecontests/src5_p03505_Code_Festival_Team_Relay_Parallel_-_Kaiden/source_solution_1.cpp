#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    Int K, A, B; cin >> K >> A >> B;
    if (A >= K) {
        cout << 1 << endl;
    } else if (A - B > 0) {
        cout << (K - B - 1) / (A - B) * 2 + 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}