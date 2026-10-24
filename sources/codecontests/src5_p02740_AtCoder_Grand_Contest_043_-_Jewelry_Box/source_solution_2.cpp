#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <tuple>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template<class C, class D, class E>
struct MinCostFlow {
    static constexpr D INF = numeric_limits<D>::max();
    int n;
    VV<E> g;
    int s, t;
    C nc, cap_flow = 0;
    D nd, flow = 0;

    V<D> dual;
    V<int> pv, pe;

    MinCostFlow(VV<E> _g, int _s, int _t, bool neg)
        : n(int(_g.size())), g(_g), s(_s), t(_t) {
        assert(s != t);
        dual = V<D>(n);
        pv = pe = V<int>(n);
        if (neg) {
            V<D> dist(n, D(INF));
            dist[s] = 0;
            for (int ph = 0; ph < n; ph++) {
                bool update = false;
                for (int i = 0; i < n; i++) {
                    if (dist[i] == INF) continue;
                    for (auto e: g[i]) {
                        if (!e.cap) continue;
                        if (dist[i] + e.dist < dist[e.to]) {
                            dist[e.to] = dist[i] + e.dist;
                            update = true;
                        }
                    }
                }
                if (!update) break;
            }
            for (int v = 0; v < n; v++) {
                dual[v] += dist[v];
            }
        }
        dual_ref();
    }

    C single_flow(C c) {
        if (nd == INF) return nc;
        c = min(c, nc);
        for (int v = t; v != s; v = pv[v]) {
            E& e = g[pv[v]][pe[v]];
            e.cap -= c;
            g[v][e.rev].cap += c;
        }
        cap_flow += c;
        flow += nd * c;
        nc -= c;
        if (!nc) dual_ref();
        return c;
    }

    void max_flow(C c) {
        while (c) {
            C f = single_flow(c);
            if (!f) break;
            c -= f;
        }
    }

    void dual_ref() {
        V<D> dist(g.size(), D(INF));
        pv = pe = V<int>(n, -1);
        struct Q {
            D key;
            int to;
            bool operator<(Q r) const { return key > r.key; }
        };
        priority_queue<Q> que;
        dist[s] = 0;
        que.push(Q{D(0), s});
        V<char> vis(n);
        while (!que.empty()) {
            int v = que.top().to; que.pop();
            if (v == t) break;
            if (vis[v]) continue;
            vis[v] = true;
            for (int i = 0; i < int(g[v].size()); i++) {
                E e = g[v][i];
                if (vis[e.to] || !e.cap) continue;
                D cost = dist[v] + e.dist + dual[v] - dual[e.to];
                if (dist[e.to] > cost) {
                    dist[e.to] = cost;
                    pv[e.to] = v; pe[e.to] = i;
                    que.push(Q{dist[e.to], e.to});
                }
            }
        }
        if (dist[t] == INF) {
            nd = INF; nc = 0;
            return;
        }
        for (int v = 0; v < n; v++) {
            if (!vis[v]) continue;
            dual[v] += dist[v] - dist[t];
        }
        nd = dual[t] - dual[s];
        nc = numeric_limits<C>::max();
        for (int v = t; v != s; v = pv[v]) {
            nc = min(nc, g[pv[v]][pe[v]].cap);
        }
    }
};

template<class C, class D, class E>
MinCostFlow<C, D, E> get_mcf(const VV<E>& g, int s, int t, bool neg = false) {
    return MinCostFlow<C, D, E>(g, s, t, neg);
}

int main() {
    int n;
    cin >> n;
    struct Stone {
        ll size, num;
        int cost;
    };
    V<int> offset(n + 1);
    VV<Stone> stones(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        offset[i + 1] = offset[i] + k;
        stones[i] = V<Stone>(k);
        for (int j = 0; j < k; j++) {
            cin >> stones[i][j].size >> stones[i][j].cost >> stones[i][j].num;            
        }
        sort(stones[i].begin(), stones[i].end(), [&](const Stone& l, const Stone& r) {
            return l.size < r.size;
        });  
    }
    int sv = offset[n], tv = sv + 1;

    struct E {
        int to, rev, cap; ll dist;
    };
    VV<E> g(tv + 1);
    auto add_edge = [&](int from, int to, int cap, ll dist) {
        g[from].push_back(E{to, int(g[to].size()), cap, dist});
        g[to].push_back(E{from, int(g[from].size())-1, 0, -dist});
    };

    const int INF_CAP = int(TEN(9));
    for (int i = 0; i < n; i++) {
        int k = int(stones[i].size());
        int bk = sv;
        for (int j = 0; j < k; j++) {
            // x_ij >= x_i{j-1}
            int nw = offset[i] + j;
            add_edge(nw, bk, INF_CAP, 0);
            add_edge(bk, nw, INF_CAP, stones[i][j].num);
            add_edge(bk, nw, stones[i][j].cost, 0);
            bk = nw;
        }
        add_edge(bk, tv, INF_CAP, 0);
        add_edge(tv, bk, INF_CAP, 0);
    }

    int m;
    cin >> m;
    for (int ph = 0; ph < m; ph++) {
        int u, v; ll w;
        cin >> u >> v >> w; u--; v--;
        int ku = int(stones[u].size());
        int kv = int(stones[v].size());
        for (int i = 0; i < ku; i++) {
            for (int j = 0; j < kv; j++) {
                if (stones[u][i].size + w < stones[v][j].size) {
                    // x_ui <= x_v(j-1)
                    int vjn1 = (j == 0 ? sv : offset[v] + j - 1);
                    add_edge(vjn1, offset[u] + i, INF_CAP, 0);
                    break;
                }
            }
        }
    }

    auto res = get_mcf<int, ll>(g, sv, tv, false);
    using Line = tuple<ll, int, ll>;
    V<Line> lines;
    while (true) {
        lines.push_back(Line{res.nd, res.cap_flow, res.flow});
//        cerr << res.nc << " " << res.nd << endl;
        if (INF_CAP / 2 < res.nc) break;
        res.single_flow(res.nc);        
    }
    //res.max_flow(TEN(9));

    int q;
    cin >> q;
    for (int ph = 0; ph < q; ph++) {
        ll a;
        scanf("%lld", &a);
        auto it = lower_bound(lines.begin(), lines.end(), Line{a, -1, -1});
        if (it == lines.end()) {
            printf("-1\n");
            continue;
        }
        int cap_flow;
        ll flow;
        tie(ignore, cap_flow, flow) = *it;
        ll sum = cap_flow * a - flow;
        printf("%lld\n", sum);
    }
    return 0;
}
