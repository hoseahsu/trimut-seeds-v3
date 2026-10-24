#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class AVL {
    int s = 0;
    struct node {
        T val;
        node *ch[2];
        int dep, size;
        node(T v, node *l = nullptr, node *r = nullptr) : val(v), dep(1), size(1) {
            ch[0] = l;
            ch[1] = r;
        }
    };
    int depth(node *t) { return t == nullptr ? 0 : t->dep; }
    int count(node *t) { return t == nullptr ? 0 : t->size; }
    node *update(node *t) {
        t->dep = max(depth(t->ch[0]), depth(t->ch[1])) + 1;
        t->size = count(t->ch[0]) + count(t->ch[1]) + 1;
        return t;
    }
    node *rotate(node *t, int b) {
        node *s = t->ch[1 - b];
        t->ch[1 - b] = s->ch[b];
        s->ch[b] = t;
        t = update(t);
        s = update(s);
        return s;
    }
    node *fetch(node *t) {
        if (t == nullptr) return t;
        if (depth(t->ch[0]) - depth(t->ch[1]) == 2) {
            if (depth(t->ch[0]->ch[1]) > depth(t->ch[0]->ch[0])) {
                t->ch[0] = rotate(t->ch[0], 0);
            }
            t = rotate(t, 1);
        } else if (depth(t->ch[0]) - depth(t->ch[1]) == -2) {
            if (depth(t->ch[1]->ch[0]) > depth(t->ch[1]->ch[1])) {
                t->ch[1] = rotate(t->ch[1], 1);
            }
            t = rotate(t, 0);
        }
        return t;
    }
    node *insert(node *t, int k, T v) {
        if (t == nullptr) return new node(v);
        int c = count(t->ch[0]), b = (k > c);
        t->ch[b] = insert(t->ch[b], k - (b ? (c + 1) : 0), v);
        update(t);
        return fetch(t);
    }
    node *erase(node *t) {
        if (t == nullptr) return nullptr;
        if (t->ch[0] == nullptr && t->ch[1] == nullptr) {
            delete t;
            return nullptr;
        }
        if (t->ch[0] == nullptr || t->ch[1] == nullptr) {
            node *res = t->ch[t->ch[0] == nullptr];
            delete t;
            return res;
        }
        node *res = new node(find(t->ch[1], 0)->val, t->ch[0], erase(t->ch[1], 0));
        delete t;
        return fetch(update(res));
    }
    node *erase(node *t, int k) {
        if (t == nullptr) return nullptr;
        int c = count(t->ch[0]);
        if (k < c) {
            t->ch[0] = erase(t->ch[0], k);
            t = update(t);
        } else if (k > c) {
            t->ch[1] = erase(t->ch[1], k - (c + 1));
            t = update(t);
        } else {
            t = erase(t);
        }
        return fetch(t);
    }
    node *find(node *t, int k) {
        if (t == nullptr) return t;
        int c = count(t->ch[0]);
        return k < c ? find(t->ch[0], k) : k == c ? t : find(t->ch[1], k - (c + 1));
    }
    int cnt(node *t, T v) {
        if (t == nullptr) return 0;
        if (t->val < v) return count(t->ch[0]) + 1 + cnt(t->ch[1], v);
        if (t->val == v) return count(t->ch[0]);
        return cnt(t->ch[0], v);
    }
    node *root;

public:
    AVL() : root(nullptr) {}
    void insert(T val) {
        root = insert(root, cnt(root, val), val);
        s++;
    }

    // 0-indexed
    T get_kth_small(int k) {
        assert(k < s);
        return find(root, k)->val;
    }
    // 0-indexed
    void erase_kth_small(int k) {
        assert(k < s);
        root = erase(root, k);
        s--;
    }

    // 0-indexed
    T get_kth_big(int k) {
        assert(k < s);
        return get_kth_small(s - 1 - k);
    }
    // 0-indexed
    void erase_kth_big(int k) {
        assert(k < s);
        erase_kth_small(s - 1 - k);
    }

    int count(T val) { return cnt(root, val); }
    int size() { return s; }
    bool empty() { return s == 0; }

    int count_lt(T val) {
        int l = -1, r = s;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (get_kth_small(m) < val) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
    int count_le(T val) {
        int l = -1, r = s;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (get_kth_small(m) <= val) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
    int count_gt(T val) {
        int l = -1, r = s;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (get_kth_big(m) > val) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
    int count_ge(T val) {
        int l = -1, r = s;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (get_kth_big(m) >= val) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

    void erase(T val) {
        int kth = count_lt(val);
        assert(get_kth_small(kth) == val);
        erase_kth_small(kth);
    }
};

class xorshift {
    uint64_t x;

public:
    xorshift() {
        mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
        x = rnd();
        for (int i = 0; i < 100; i++) {
            random();
        }
    }

    uint64_t random() {
        x = x ^ (x << 7);
        return x = x ^ (x >> 9);
    }
};

using T = long long;

struct SumMonoid {
    static constexpr T id() { return 0; }

    static T op(T a, T b) { return a + b; }
};

struct MinMonoid {
    static constexpr T id() { return 2e18; }

    static T op(T a, T b) { return min(a, b); }
};

// 本来はSumMonoid用
struct UpdateMonoid {
    static constexpr T id() { return 2e18; }

    static T op(T a, T b) { return b; }
};

struct Modifier {
    // lazyの結果によってaccがどう変わるか。szは部分木のサイズ
    static T op(T a, T b, int sz) { return b == UpdateMonoid::id() ? a : b * sz; }
};

template <class Monoid, class OperatorMonoid>
class ImplicitTreap {
    xorshift rnd;

    struct Node {
        T value, acc, lazy;
        int priority, cnt;
        bool rev;
        Node *l, *r;

        Node(T value, int priority)
            : value(value),
              acc(Monoid::id()),
              lazy(OperatorMonoid::id()),
              priority(priority),
              cnt(1),
              rev(false),
              l(nullptr),
              r(nullptr) {}
    } *root = nullptr;

    using Tree = Node *;

    int cnt(Tree t) { return t ? t->cnt : 0; }

    T acc(Tree t) { return t ? t->acc : Monoid::id(); }

    void update_cnt(Tree t) {
        if (t) {
            t->cnt = 1 + cnt(t->l) + cnt(t->r);
        }
    }

    void update_acc(Tree t) {
        if (t) {
            t->acc = Monoid::op(acc(t->l), Monoid::op(t->value, acc(t->r)));
        }
    }

    void pushup(Tree t) { update_cnt(t), update_acc(t); }

    void pushdown(Tree t) {
        if (t && t->rev) {
            t->rev = false;
            swap(t->l, t->r);
            if (t->l) t->l->rev ^= 1;
            if (t->r) t->r->rev ^= 1;
        }
        if (t && t->lazy != OperatorMonoid::id()) {
            if (t->l) {
                t->l->lazy = OperatorMonoid::op(t->l->lazy, t->lazy);
                t->l->acc = Modifier::op(t->l->acc, t->lazy, cnt(t->l));
            }
            if (t->r) {
                t->r->lazy = OperatorMonoid::op(t->r->lazy, t->lazy);
                t->r->acc = Modifier::op(t->r->acc, t->lazy, cnt(t->r));
            }
            t->value = Modifier::op(t->value, t->lazy, 1);
            t->lazy = OperatorMonoid::id();
        }
        pushup(t);
    }

    void split(Tree t, int key, Tree &l, Tree &r) {
        if (!t) {
            l = r = nullptr;
            return;
        }
        pushdown(t);
        int implicit_key = cnt(t->l) + 1;
        if (key < implicit_key) {
            split(t->l, key, l, t->l), r = t;
        } else {
            split(t->r, key - implicit_key, t->r, r), l = t;
        }
        pushup(t);
    }

    void insert(Tree &t, int key, Tree item) {
        Tree t1, t2;
        split(t, key, t1, t2);
        merge(t1, t1, item);
        merge(t, t1, t2);
    }

    void merge(Tree &t, Tree l, Tree r) {
        pushdown(l);
        pushdown(r);
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        }
        pushup(t);
    }

    void erase(Tree &t, int key) {
        Tree t1, t2, t3;
        split(t, key + 1, t1, t2);
        split(t1, key, t1, t3);
        merge(t, t1, t2);
    }

    void update(Tree t, int l, int r, T x) {
        if (l >= r) return;
        Tree t1, t2, t3;
        split(t, l, t1, t2);
        split(t2, r - l, t2, t3);
        t2->lazy = OperatorMonoid::op(t2->lazy, x);
        t2->acc = Modifier::op(t2->acc, x, cnt(t2));
        merge(t2, t2, t3);
        merge(t, t1, t2);
    }

    T query(Tree t, int l, int r) {
        if (l == r) return Monoid::id();
        Tree t1, t2, t3;
        split(t, l, t1, t2);
        split(t2, r - l, t2, t3);
        T ret = t2->acc;
        merge(t2, t2, t3);
        merge(t, t1, t2);
        return ret;
    }

    // [l, r)の中で左から何番目か
    int find(Tree t, T x, int offset, bool left = true) {
        if (Monoid::op(t->acc, x) == x) {
            return -1;
        } else {
            if (left) {
                if (t->l && Monoid::op(t->l->acc, x) != x) {
                    return find(t->l, x, offset, left);
                } else {
                    return (Monoid::op(t->value, x) != x) ? offset + cnt(t->l)
                                                          : find(t->r, x, offset + cnt(t->l) + 1, left);
                }
            } else {
                if (t->r && Monoid::op(t->r->acc, x) != x) {
                    return find(t->r, x, offset + cnt(t->l) + 1, left);
                } else {
                    return (Monoid::op(t->value, x) != x) ? offset + cnt(t->l) : find(t->l, x, offset, left);
                }
            }
        }
    }

    void reverse(Tree t, int l, int r) {
        if (l > r) return;
        Tree t1, t2, t3;
        split(t, l, t1, t2);
        split(t2, r - l, t2, t3);
        t2->rev ^= 1;
        merge(t2, t2, t3);
        merge(t, t1, t2);
    }

    // [l, r)の先頭がmになるようにシフトさせる。std::rotateと同じ仕様
    void rotate(Tree t, int l, int m, int r) {
        reverse(t, l, r);
        reverse(t, l, l + r - m);
        reverse(t, l + r - m, r);
    }

    void dump(Tree t) {
        if (!t) return;
        pushdown(t);
        dump(t->l);
        cout << t->value << " ";
        dump(t->r);
    }

public:
    ImplicitTreap() {}

    ImplicitTreap(vector<T> as) {
        ::reverse(as.begin(), as.end());
        for (T a : as) {
            insert(0, a);
        }
    }

    int size() { return cnt(root); }

    void insert(int pos, T x) { insert(root, pos, new Node(x, rnd.random())); }

    void update(int l, int r, T x) { update(root, l, r, x); }

    T query(int l, int r) { return query(root, l, r); }

    // 二分探索。[l, r)内のkでMonoid::op(tr[k], x) != xとなる最左/最右のもの。存在しない場合は-1
    // たとえばMinMonoidの場合、x未満の最左/最右の要素の位置を返す
    int binary_search(int l, int r, T x, bool left = true) {
        if (l >= r) return -1;
        Tree t1, t2, t3;
        split(root, l, t1, t2);
        split(t2, r - l, t2, t3);
        int ret = find(t2, x, l, left);
        merge(t2, t2, t3);
        merge(root, t1, t2);
        return ret;
    }

    void erase(int pos) { erase(root, pos); }

    void reverse(int l, int r) { reverse(root, l, r); }

    void rotate(int l, int m, int r) { rotate(root, l, m, r); }

    void dump() {
        dump(root);
        cout << endl;
    }

    T operator[](int pos) { return query(pos, pos + 1); }
};

struct PrioritySum {
    ImplicitTreap<SumMonoid, UpdateMonoid> tr;
    ImplicitTreap<MinMonoid, UpdateMonoid> tr2;
    int cnt = 0;

    void add(T a) {
        int p = tr2.binary_search(0, tr2.size(), a);
        if (p == -1) {
            tr.insert(tr.size(), a);
            tr2.insert(tr2.size(), a);
        } else {
            tr.insert(p, a);
            tr2.insert(p, a);
        }
        cnt++;
    }

    void erase_at(int k) {
        assert(0 <= k && k < cnt);
        tr.erase(k);
        tr2.erase(k);
        cnt--;
    }

    int size() const { return cnt; }

    T sum(int k) { return tr.query(0, k); }

    T operator[](int k) { return tr[k]; }

    void dump() { tr.dump(); }
};

long long mergecount(vector<pair<int, int>> &as, int c) {
    long long ret = 0;
    int n = as.size();
    if (n > 1) {
        vector<pair<int, int>> bs(as.begin(), as.begin() + n / 2);
        vector<pair<int, int>> cs(as.begin() + n / 2, as.end());
        ret += mergecount(bs, c);
        ret += mergecount(cs, c);
        AVL<int> avl;
        PrioritySum psum;
        int allcnt = 0;
        long long allsum = 0;
        for (auto &b : bs) {
            avl.insert(b.second);
            psum.add(b.second);
            allcnt++;
            allsum += b.second;
        }

        for (int i = 0, j = 0, k = 0; i < n; i++) {
            if (k == cs.size()) {
                as[i] = bs[j++];
            } else if (j == bs.size()) {
                as[i] = cs[k++];
            } else if (bs[j] <= cs[k]) {
                int w = bs[j].second;
                as[i] = bs[j++];
                assert(psum[avl.count_gt(w)] == w);
                psum.erase_at(avl.count_gt(w));
                avl.erase(w);
                allcnt--;
                allsum -= w;
            } else {
                int w = cs[k].second;
                as[i] = cs[k++];

                int ge_cnt = avl.count_ge(w);
                long long cost = 0;
                cost += psum.sum(ge_cnt) + 1LL * w * c * ge_cnt;
                cost += (allsum - psum.sum(ge_cnt)) * c + 1LL * w * (allcnt - ge_cnt);

                ret += cost;
            }
        }
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> as;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        as.emplace_back(a, b);
    }

    cout << mergecount(as, c) << endl;
}

