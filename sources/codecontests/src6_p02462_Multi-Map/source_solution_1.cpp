#include <iostream>
#include <map>

int main() {
    int q;
    std::cin >> q;

    std::multimap<std::string, int> M;
    for (int i = 0; i < q; i++) {
        int op;
        std::string key;
        std::cin >> op;
        
        if (op == 0) {
            int x;
            std::cin >> key >> x;
            M.insert(std::make_pair(key, x));
        } else if (op == 1) {
            std::cin >> key;
            auto range = M.equal_range(key);
            for (auto it = range.first; it != range.second; it++) {
                std::cout << it->second << std::endl;
            }
        } else if (op == 2) {
            std::cin >> key;
            M.erase(key);
        } else if (op == 3) {
            std::string L, R;
            std::cin >> L >> R;
            auto begin = M.lower_bound(L);
            auto end = M.upper_bound(R);
            for (auto it = begin; it != end; it++) {
                std::cout << it->first << " " << it->second << std::endl;
            }
        }
    }
}

