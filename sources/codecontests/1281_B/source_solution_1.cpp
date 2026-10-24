#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 < s2) {
      cout << s1 << endl;
      continue;
    }
    bool flag = false;
    for (int i = 0; i < s1.size(); i++) {
      if (flag) break;
      for (int j = i; j < s1.size(); j++) {
        if (j == i) continue;
        if (s1[i] > s1[j]) {
          swap(s1[i], s1[j]);
          if (s1 < s2) {
            flag = true;
            break;
          } else
            swap(s1[i], s1[j]);
        }
      }
    }
    if (!flag)
      cout << "---" << endl;
    else
      cout << s1 << endl;
  }
}
