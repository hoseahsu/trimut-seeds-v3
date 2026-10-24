#include <bits/stdc++.h>
int main() {
  int n, k;
  std::deque<int> msg;
  std::set<int> a;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int m;
    std::cin >> m;
    auto it = a.find(m);
    if (it == a.end()) {
      if (a.size() == k) {
        int last = msg.back();
        a.erase(a.find(last));
        msg.pop_back();
      }
      msg.push_front(m);
      a.insert(m);
    }
  }
  std::cout << a.size() << std::endl;
  for (auto it = msg.begin(); it != msg.end(); ++it) {
    std::cout << *it << " ";
  }
}
