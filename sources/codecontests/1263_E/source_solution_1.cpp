#include <bits/stdc++.h>
using namespace std;
string s;
int n;
class Stack {
 public:
  stack<int> st;
  stack<int> max_st;
  stack<bool> valid_st;
  int cnt = 0;
  void push(int x) {
    cnt += x;
    if (cnt < 0)
      valid_st.push(false);
    else
      valid_st.push(valid_st.size() > 0 ? valid_st.top() : true);
    st.push(x);
    max_st.push(max_st.size() > 0 ? max(cnt, max_st.top()) : cnt);
  }
  void pop() {
    cnt -= st.top();
    max_st.pop();
    valid_st.pop();
    st.pop();
  }
  int depth() { return max_st.size() > 0 ? max_st.top() : 0; }
  int top() { return st.top(); }
  bool is_valid() { return valid_st.empty() || valid_st.top(); }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  cin >> s;
  Stack left, right;
  int pos = 0;
  for (int i = 0; i < n; ++i) right.push(0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      right.pop();
      right.push(-1);
    } else if (s[i] == ')') {
      right.pop();
      right.push(1);
    } else if (s[i] == 'R') {
      left.push(-right.top());
      right.pop();
      ++pos;
    } else if (s[i] == 'L') {
      if (pos > 0) {
        right.push(-left.top());
        left.pop();
        --pos;
      }
    } else {
      right.pop();
      right.push(0);
    }
    if (left.is_valid() && right.is_valid() && left.cnt == right.cnt) {
      cout << max({left.depth(), right.depth()}) << " ";
    } else {
      cout << "-1 ";
    }
  }
  return 0;
}
