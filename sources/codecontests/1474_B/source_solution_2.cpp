#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int64_t> primes {2};

void solveCase() {
    int64_t d;
    std::cin >> d;

    int64_t lb = *std::lower_bound(begin(primes), end(primes), d + 1);
    int64_t ub = *std::upper_bound(begin(primes), end(primes), std::max(d * 2, lb + d - 1));

    std::cout << lb * ub << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int MAX = 1e6 + 1;
    std::vector<bool> notprime(MAX);

    for (int64_t i = 3; i < MAX; i += 2) {
        if (notprime[i]) continue;

        primes.push_back(i);
        for (int64_t j = i * i; j < MAX; j += i << 1) {
            notprime[j] = true;
        }
    }

    int T;
    std::cin >> T;

    while (T--) {
        solveCase();
    }

    return 0;
}

