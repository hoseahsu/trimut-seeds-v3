#include <bits/stdc++.h>
using namespace std;

typedef int64_t Int;
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << '\n'; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) cout << " ";
    cout << fixed << setprecision(15) << head;
    print_space_enable = true;
    print(std::forward<Tail>(tail)...);
}

template<typename T>
void print(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << std::endl;
}

int main() {
    Int s, t, d;
    cin >> s >> t >> d;
    vector<Int> w(d);
    for (Int i = 0; i < d; i++) {
        cin >> w[i];
    }
    Int sum = accumulate(all(w), (Int)0);
    if (sum >= 0) {
        for (Int i = 0; i < d; i++) {
            s += w[i];
            if (s <= t) {
                print(i + 1);
                return 0;
            }
        }
        print(-1);
        return 0;
    }
    Int mi = 0;
    Int x = 0;
    for (Int i = 0; i < d; i++) {
        x += w[i];
        mi = min(mi, x);
    }
    Int a = max((s - t + mi) / abs(sum), (Int)0);
    if ((s - t + mi) > 0 and (s - t + mi) % abs(sum) != 0) a++;
    Int cur = s + a * sum;
    Int res = a * d;
    for (Int i = 0; i < d; i++) {
        res++;
        cur += w[i];
        if (cur <= t) {
            print(res);
            return 0;
        }
    }
    return 0;
}

