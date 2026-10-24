// Author: πα

#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        set<int> s;
        while(n--)
        {
            int d;
            cin >> d;
            s.insert(d+s.count(d));
        }
        cout << s.size() << '\n';
    }
    return 0;
}
