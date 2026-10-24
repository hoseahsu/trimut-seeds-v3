#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ds(n);
    std::map<int, std::vector<std::pair<int, int>>> xby, yby;

    for (int i = 0; i < n; ++i) {
        int x, y;
        char c;
        std::cin >> x >> y >> c;

        int d;
        for (d = 0; d < 4; ++d) {
            if (c == "><v^"[d]) break;
        }

        ds[i] = d;
        xby[x].emplace_back(y, i);
        yby[y].emplace_back(x, i);
    }

    std::vector<std::vector<int>> oto(n, std::vector<int>(4, -1));
    for (auto& p : xby) {
        auto& ys = p.second;
        std::sort(ys.begin(), ys.end());

        for (int i = 0; i + 1 < (int)ys.size(); ++i) {
            int u = ys[i].second, v = ys[i + 1].second;
            oto[u][2] = v;
            oto[v][3] = u;
        }
    }

    for (auto& p : yby) {
        auto& xs = p.second;
        std::sort(xs.begin(), xs.end());

        for (int i = 0; i + 1 < (int)xs.size(); ++i) {
            int u = xs[i].second, v = xs[i + 1].second;
            oto[u][0] = v;
            oto[v][1] = u;
        }
    }

    int ans = 0;
    for (int s = 0; s < n; ++s) {
        auto to = oto;
        int cnt = 0;

        int v = s;
        while (v != -1) {
            int p = to[v][0], q = to[v][1];
            if (p != -1) to[p][1] = q;
            if (q != -1) to[q][0] = p;

            p = to[v][2], q = to[v][3];
            if (p != -1) to[p][3] = q;
            if (q != -1) to[q][2] = p;

            v = to[v][ds[v]];
            ++cnt;
        }

        ans = std::max(ans, cnt);
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}

