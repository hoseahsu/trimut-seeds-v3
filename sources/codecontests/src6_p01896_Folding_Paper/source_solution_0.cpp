#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10LL * TEN(n-1); }

using P = pair<int, int>;
bool ok(vector<P> v) {
    for (auto &p: v) {
        if (p.first > p.second) {
            swap(p.first, p.second);
        }
    }
    sort(begin(v), end(v));
    vector<P> st;
    for (auto p: v) {
        while (st.size() && st.back().second < p.first) {
            st.pop_back();
        }
        if (st.size() && st.back().second < p.second) {
            return false;
        }
        st.push_back(p);
    }
    return true;
}

int main() {
    int h, w;
    scanf("%d %d", &h, &w);
    int n = h*w;
    int rid[n];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        rid[a] = i;
    }

    for (int y = 0; y < h; y++) {
        vector<P> v[2];
        for (int x = 0; x < w-1; x++) {
            int id = y*w+x;
            v[x%2].push_back(P(rid[id], rid[id+1]));
        }
        if (!ok(v[0]) || !ok(v[1])) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int x = 0; x < w; x++) {
        vector<P> v[2];
        for (int y = 0; y < h-1; y++) {
            int id = y*w+x;
            v[y%2].push_back(P(rid[id], rid[id+w]));
        }
        if (!ok(v[0]) || !ok(v[1])) {
            cout << "NO" << endl;
            return 0;
        }        
    }
    cout << "YES" << endl;
    return 0;
}