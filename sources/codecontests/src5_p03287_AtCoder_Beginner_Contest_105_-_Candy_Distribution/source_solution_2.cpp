#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    long long answer = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        sum += x;
        sum %= m;
        answer += mp[sum];
        ++mp[sum];
    }
    cout << answer;
}