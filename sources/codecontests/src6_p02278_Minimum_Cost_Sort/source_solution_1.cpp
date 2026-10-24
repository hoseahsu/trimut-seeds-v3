#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 1000
#define MAX_W 10000

int n, A[MAX_N], s, B[MAX_N], T[MAX_W];

int solve()
{
	int ans = 0, count = 0;
	bool V[MAX_N];
    memset(V, false, sizeof(V));
    memcpy(B, A, sizeof(int) * n);
    sort(B, B + n);
    for (int i = 0; i < n; i++) T[B[i]] = i;
    for (int i = 0; i < n; i++) {
        if (V[i]) continue;
        int cur = i;
        int S = 0;
        int m = MAX_W;
        int an = 0;
        while (1) {
            V[cur] = true;
            an++;
            int v = A[cur];
            m = min(m, v);
            S += v;
            cur = T[v];
            if (V[cur]) break;
        }
        ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
    }
    return ans;
}

int main()
{
    cin >> n;
    s = MAX_W;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        s = min(s, A[i]);
    }
    int ans = solve();
    cout << ans << endl;
    return 0;
}