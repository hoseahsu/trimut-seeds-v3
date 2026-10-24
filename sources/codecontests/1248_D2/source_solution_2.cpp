#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++)
    os << *i << (i == end(v) - 1 ? "" : " ");
  return os;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++) is >> *i;
  return is;
}
int get_count(string s) {
  vector<int> vec(s.size());
  int min_val = 1;
  for (int i = 0; i < s.size(); i++) {
    vec[i] = s[i] == '(' ? 1 : -1;
    if (i > 0) vec[i] += vec[i - 1];
    min_val = min(min_val, vec[i]);
  }
  int cnt = 0;
  for (int x : vec)
    if (x == min_val) cnt++;
  return cnt;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> vec(s.size());
  int min_val = n;
  int last_close = -1;
  for (int i = 0; i < s.size(); i++) {
    vec[i] = s[i] == '(' ? 1 : -1;
    if (i > 0) vec[i] += vec[i - 1];
    min_val = min(min_val, vec[i]);
    if (s[i] == ')') last_close = i;
  }
  if (vec.back() != 0) {
    cout << "0\n1 1";
    return 0;
  }
  int ans = 0;
  int left_open = -1;
  int diff = 0;
  int best_score = 0;
  pair<int, int> repl = {0, 0};
  for (int i = 0; i < n; i++) {
    bool stop = abs(vec[i] - min_val) <= 1 || i == last_close;
    if (stop && left_open > -1) {
      if (diff > best_score) {
        best_score = diff;
        repl = {left_open, i};
      }
      left_open = -1;
    }
    if (stop) continue;
    bool start = s[i] == '(';
    if (start && left_open == -1) {
      diff = 0;
      left_open = i;
    }
    if (left_open > -1) {
      if (abs(vec[i] - min_val) == 2) diff++;
    }
  }
  best_score += get_count(s);
  diff = 0;
  left_open = -1;
  for (int i = 0; i < n; i++) {
    bool stop = abs(vec[i] - min_val) <= 0 || i == last_close;
    if (stop && left_open > -1) {
      if (diff > best_score) {
        best_score = diff;
        repl = {left_open, i};
      }
      left_open = -1;
    }
    if (stop) continue;
    bool start = s[i] == '(';
    if (start && left_open == -1) {
      diff = 0;
      left_open = i;
    }
    if (left_open > -1) {
      if (abs(vec[i] - min_val) == 1) diff++;
    }
  }
  int first_pos = -1;
  int last_pos = -1;
  bool on = false;
  for (int i = 0; i < n; i++) {
    int d = abs(vec[i] - min_val);
    if (d == 0 && s[i] == ')' && first_pos < 0) {
      first_pos = i;
    }
    if (d == 0 && first_pos >= 0) on = true;
    if (d > 0 && s[i] == '(' && on) {
      on = false;
      last_pos = i;
    }
  }
  if (on) last_pos = -1;
  int first_pos1 = -1;
  int last_pos1 = -1;
  on = false;
  for (int i = 0; i < n; i++) {
    int d = abs(vec[i] - min_val);
    if (d <= 1 && s[i] == ')' && first_pos1 < 0) {
      first_pos1 = i;
    }
    if (d <= 1 && first_pos1 >= 0) on = true;
    if (d > 1 && s[i] == '(' && on) {
      on = false;
      last_pos1 = i;
    }
  }
  int a_sub = best_score;
  int a_add1 = -1;
  int a_add2 = -1;
  if (first_pos >= 0 && last_pos >= 0) {
    string str = s;
    swap(str[first_pos], str[last_pos]);
    a_add1 = get_count(str);
  }
  if (first_pos1 >= 0 && last_pos1 >= 0) {
    string str = s;
    swap(str[first_pos1], str[last_pos1]);
    a_add2 = get_count(str);
  }
  if (n == 300000 && a_sub == 2) {
  }
  if (a_sub >= a_add1 && a_sub >= a_add2) {
    cout << a_sub << "\n" << repl.first + 1 << " " << repl.second + 1;
  } else if (a_add1 >= a_sub && a_add1 >= a_add2) {
    cout << a_add1 << "\n  " << first_pos + 1 << " " << last_pos + 1;
  } else {
    cout << a_add2 << "\n   " << first_pos1 + 1 << " " << last_pos1 + 1;
  }
  return 0;
}
