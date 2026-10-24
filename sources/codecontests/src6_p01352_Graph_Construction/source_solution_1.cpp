#include <cassert>
#include <cmath>
#include <cstdio>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
using namespace std;

struct disjoint_sets {
    vector<int> data;
    disjoint_sets() = default;
    explicit disjoint_sets(size_t n) : data(n, -1) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int set_size(int i) { return - data[find_root(i)]; }
    int union_sets(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (set_size(i) < set_size(j)) swap(i,j);
            data[i] += data[j];
            data[j] = i;
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
};
struct popable_disjoint_sets {
    vector<int> data;
    stack<pair<int, int> > history;
    explicit popable_disjoint_sets(disjoint_sets const & a) : data(a.data) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { while (not is_root(i)) i = find_root(data[i]); return i; }
    int set_size(int i) { return - data[find_root(i)]; }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
    void push(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (set_size(i) < set_size(j)) swap(i,j);
            history.emplace(data[i], data[j]);
            history.emplace(i, j);
            data[i] += data[j];
            data[j] = i;
        }
    }
    void pop() {
        while (not history.empty()) {
            int i, j; tie(i, j) = history.top(); history.pop();
            tie(data[i], data[j]) = history.top(); history.pop();
        }
    }
};

int main() {
    // input
    int n, k; scanf("%d%d", &n, &k);
    vector<int> type(k), u(k), v(k);
    repeat (i, k) {
        scanf("%d%d%d", &type[i], &u[i], &v[i]);
    }
    // solve
    assert (n < (1 << 16));
    auto pack = [&](int u, int v) { return uint32_t(u << 16) + uint32_t(v); };
    auto unpack = [&](uint32_t packed) { return make_pair(packed >> 16, packed & 0xffff); };
    int sqrt_k = sqrt(k) + 1;
    unordered_set<uint32_t> edges;
    for (int l = 0; l < k; l += sqrt_k) { // square root decomposition
        int r = min(k, l + sqrt_k);
        unordered_set<uint32_t> dangling;
        repeat_from (i, l, r) {
            if (type[i] == 2) {
                uint32_t packed = pack(u[i], v[i]);
                if (edges.count(packed)) {
                    edges.erase(packed);
                    dangling.insert(packed);
                }
            }
        }
        disjoint_sets ds(n);
        for (uint32_t packed : edges) {
            int i, j; tie(i, j) = unpack(packed);
            ds.union_sets(i, j);
        }
        popable_disjoint_sets pds(ds);
        repeat_from (i, l, r) {
            if (type[i] == 1) {
                dangling.insert(pack(u[i], v[i]));
            } else if (type[i] == 2) {
                dangling.erase(pack(u[i], v[i]));
            } else if (type[i] == 3) {
                for (uint32_t packed : dangling) {
                    int i, j; tie(i, j) = unpack(packed);
                    pds.push(i, j);
                }
                printf("%s\n", pds.is_same(u[i], v[i]) ? "YES" : "NO"); // output
                pds.pop();
            }
        }
        for (uint32_t packed : dangling) {
            edges.insert(packed);
        }
    }
    return 0;
}