#include <bits/stdc++.h>
using namespace std;
int freq1[256], freq2[256];
int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    freq1[s[i]]++;
  }
  for (int i = 0; i < t.size(); i++) {
    freq2[t[i]]++;
  }
  bool rem = false;
  bool invalid = false;
  for (int i = 0; i < 256; i++) {
    if (freq1[i] > freq2[i]) {
      rem = true;
    } else if (freq1[i] < freq2[i]) {
      invalid = true;
    }
  }
  if (invalid)
    cout << "need tree\n";
  else {
    int j = 0;
    int found = 0;
    for (int i = 0; i < t.size(); i++) {
      while (j < s.size() && s[j] != t[i]) j++;
      if (j < s.size()) {
        found++;
        j++;
      }
    }
    bool swap = false;
    if (found != t.size()) swap = true;
    if (rem && swap)
      cout << "both\n";
    else if (rem)
      cout << "automaton\n";
    else if (swap)
      cout << "array\n";
  }
  return 0;
}
