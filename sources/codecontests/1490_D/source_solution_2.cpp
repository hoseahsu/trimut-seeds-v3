#include <bits/stdc++.h>

using namespace std;

const int nmax = 107;
int tc, n, a[nmax], d[nmax];


void recur(int l, int r, int cnt)
{
    if( l>r ) return ;

    int p = l;
    for( int i=l; i<=r; ++i ) {
        if( a[i]>a[p] ) {
            p = i;
        }
    }

    d[p] = cnt;

    recur(l, p-1, cnt+1);
    recur(p+1, r, cnt+1);
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for( int i=1; i<=n; ++i )
            cin >> a[i];

        recur(1, n, 0);

        for( int i=1; i<=n; ++i )
            cout << d[i] << ' ' ;

        cout << endl;
    }
    return 0;
}
