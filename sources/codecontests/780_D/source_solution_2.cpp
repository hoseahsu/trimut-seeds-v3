#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
struct node {
  string first;
  char second;
  int num;
};
bool cmp(node& left, node& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  }
  return left.first < right.first;
}
void block(vector<node>& a, int l, int r) {
  int l_ = l, r_ = l;
  for (int i = l + 1; i <= r; ++i) {
    if (a[i - 1].first[1] != a[i].first[1]) {
      bool o = true;
      for (int j = l_ + 1; j <= r_; ++j) {
        if (a[j - 1].first[2] == a[j].first[2]) {
          o = false;
        }
      }
      if (o) {
        for (int j = l_; j <= r_; ++j) {
          ans[a[j].num] = a[j].first;
        }
      } else {
        o = true;
        map<string, int> m;
        for (int j = l_; j <= r_; ++j) {
          string buf;
          buf += a[j].first[0];
          buf += a[j].first[1];
          buf += a[j].second;
          m[buf]++;
        }
        for (auto next : m) {
          if (next.second >= 2) {
            o = false;
          }
        }
        if (o) {
          for (int j = l_; j <= r_; ++j) {
            string buf;
            buf += a[j].first[0];
            buf += a[j].first[1];
            buf += a[j].second;
            ans[a[j].num] = buf;
          }
        }
      }
      l_ = r_ = i;
    } else {
      r_++;
    }
  }
  bool o = true;
  for (int j = l_ + 1; j <= r_; ++j) {
    if (a[j - 1].first[2] == a[j].first[2]) {
      o = false;
    }
  }
  if (o) {
    for (int j = l_; j <= r_; ++j) {
      ans[a[j].num] = a[j].first;
    }
  } else {
    o = true;
    map<string, int> m;
    for (int j = l_; j <= r_; ++j) {
      string buf;
      buf += a[j].first[0];
      buf += a[j].first[1];
      buf += a[j].second;
      m[buf]++;
    }
    for (auto next : m) {
      if (next.second >= 2) {
        o = false;
      }
    }
    if (o) {
      for (int j = l_; j <= r_; ++j) {
        string buf;
        buf += a[j].first[0];
        buf += a[j].first[1];
        buf += a[j].second;
        ans[a[j].num] = buf;
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  ans.resize(n);
  vector<node> a(n);
  for (int i = 0; i < n; ++i) {
    string l, r;
    cin >> l >> r;
    string need_l;
    for (int j = 0; j < 3; ++j) {
      need_l = need_l + l[j];
    }
    char c = r[0];
    a[i].first = need_l;
    a[i].second = c;
    a[i].num = i;
  }
  sort(a.begin(), a.end(), cmp);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i].first[0] != a[i - 1].first[0]) {
      block(a, l, r);
      l = r = i;
    } else {
      r++;
    }
  }
  block(a, l, r);
  bool o = true;
  for (int i = 0; i < n; ++i) {
    if (ans[i] == "") {
      o = false;
    }
  }
  if (o) {
    cout << "YES\n";
    for (auto now : ans) {
      cout << now << "\n";
    }
  } else {
    cout << "NO";
  }
  return 0;
}
