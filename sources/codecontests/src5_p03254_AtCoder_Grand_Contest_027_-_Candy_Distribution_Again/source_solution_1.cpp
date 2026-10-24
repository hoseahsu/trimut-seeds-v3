#include <bits/stdc++.h>

using namespace std;

long long n, a[105], x;

int main() {

cin >> n >> x;

for (int i = 1; i <= n; ++i){
    cin >> a[i];
}
sort(a + 1, a + 1 + n);

for (int i = 1; i <= n; ++i){
    if(a[i] <= x) x -= a[i];
    else {cout << i - 1; return 0;}
}

if (x != 0) cout << n - 1;
else cout << n;

return 0;

}
