#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

template<typename T>
struct WeightedQuickFind {
    vector<int> par;
    vector<T> weight;
    vector<vector<int>> groups;
    WeightedQuickFind(int sz) : par(sz), weight(sz) {
        iota(begin(par), end(par), 0);
        for (int i = 0; i < sz; i++) groups.emplace_back(1, i);
    }
    void merge(int x, int y, T w) {
        if (par[x] == par[y]) return ;
        if (groups[par[x]].size() > groups[par[y]].size()) swap(x, y), w = -w;
        int p = par[x];
        w += weight[x] - weight[y];
        for (int i: groups[par[x]]) {
            weight[i] -= w, par[i] = par[y], groups[par[y]].emplace_back(i);
        }
        groups[p].clear();
    }
    bool is_same(int x, int y) { return par[x] == par[y]; }
    T diff(int x, int y) { return weight[y] - weight[x]; }
    void update(int x, int y, T w) {
        weight[x] += w, weight[y] += w;
        if (par[x] != par[y]) merge(x, y, w);
    }
};

int main() {
    int n, q; cin >> n >> q;
    WeightedQuickFind<int> wqf(n);
    while (q--) {
        string s; cin >> s;
        int a, b; cin >> a >> b; a--, b--;
        if (s[0] == 'I') {
            int c; cin >> c;
            wqf.update(a, b, c);
        }
        if (s[0] == 'C') {
            if (wqf.is_same(a, b)) {
                cout << wqf.diff(a, b) << endl;
            } else {
                cout << "WARNING" << endl;
            }
        }
    }
    return 0;
}

