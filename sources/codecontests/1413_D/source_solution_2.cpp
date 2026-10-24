#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
stack<int> st;
int ans[maxn];
int main() {
  int t;
  scanf("%d", &t);
  getchar();
  int mi = 0;
  int cnt = 0;
  for (int i = 0; i < 2 * t; i++) {
    char ch;
    scanf(" %c", &ch);
    if (ch == '+') {
      mi = 0;
      st.push(cnt++);
    } else {
      int cur;
      scanf("%d", &cur);
      if (cur < mi) {
        cout << "NO" << endl;
        return 0;
      }
      mi = cur;
      if (st.empty()) {
        cout << "NO\n";
        return 0;
      }
      if (ans[st.top() + 1] > cur) {
        cout << "NO" << endl;
        return 0;
      }
      ans[st.top()] = cur;
      st.pop();
    }
  }
  printf("YES\n");
  for (int i = 0; i < t; i++) {
    printf("%d ", ans[i]);
  }
}
