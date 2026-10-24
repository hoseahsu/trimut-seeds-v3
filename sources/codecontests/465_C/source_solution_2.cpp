#include <bits/stdc++.h>
using namespace std;
int n, p;
string s, answer, original;
string &min(string &a, string &b) { return a < b ? a : b; }
bool check(int pos) {
  if (pos - 2 >= 0)
    return !(s[pos - 2] == s[pos - 1] || s[pos] == s[pos - 1] ||
             s[pos - 2] == s[pos]);
  if (pos - 1 >= 0) return !(s[pos] == s[pos - 1]);
  return true;
}
void rec(int num) {
  if (num == n) {
    answer = min(answer, s);
    return;
  }
  for (s[num] = 'a'; s[num] < 'a' + p; ++s[num]) {
    if (check(num)) {
      rec(num + 1);
      break;
    }
  }
}
int main() {
  cin >> n >> p;
  cin >> original;
  answer.append("~");
  for (int ind = 0; ind < n; ++ind) {
    s = original;
    for (s[ind]++; s[ind] < 'a' + p; ++s[ind]) {
      if (check(ind)) {
        rec(ind + 1);
        break;
      }
    }
  }
  if (!answer.compare("~"))
    cout << "NO" << endl;
  else
    cout << answer << endl;
  return 0;
}
