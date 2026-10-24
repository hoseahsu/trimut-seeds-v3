#include <bits/stdc++.h>
using namespace std;
int main() {
  string name, word = "heidi";
  getline(cin, name);
  vector<string> v;
  vector<string> v2(word.size());
  bool h, e, k, d, I;
  h = e = k = d = I = false;
  unsigned long int i = 0, j = 0;
  while (i < name.size()) {
    if (name[i] != 'h') {
      i++;
    } else {
      v.resize(v.size() + 1);
      v[k] = name[i];
      j++;
      h = true;
      break;
    }
  }
  if (h) {
    while (i < name.size()) {
      if (name[i] != 'e') {
        i++;
      } else {
        v.resize(v.size() + 1);
        v[j] = name[i];
        j++;
        e = true;
        break;
      }
    }
  }
  if (e) {
    while (i < name.size()) {
      if (name[i] != 'i') {
        i++;
      } else {
        v.resize(v.size() + 1);
        v[j] = name[i];
        j++;
        k = true;
        break;
      }
    }
  }
  if (k) {
    while (i < name.size()) {
      if (name[i] != 'd') {
        i++;
      } else {
        v.resize(v.size() + 1);
        v[j] = name[i];
        j++;
        d = true;
        break;
      }
    }
  }
  if (d) {
    while (i < name.size()) {
      if (name[i] != 'i') {
        i++;
      } else {
        v.resize(v.size() + 1);
        v[j] = name[i];
        j++;
        I = true;
        break;
      }
    }
  }
  if (h && e && d && k && I) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
