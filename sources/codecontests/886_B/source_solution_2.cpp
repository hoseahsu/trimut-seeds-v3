#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  std::set<int> st;
  std::stack<int> stck;
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    st.insert(a);
    stck.push(a);
  }
  while (!stck.empty()) {
    if (st.size() == 1) {
      std::cout << *st.begin() << std::endl;
      return 0;
    }
    st.erase(stck.top());
    stck.pop();
  }
  return 0;
}
