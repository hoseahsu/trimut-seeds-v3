#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void yes() {
  cout << "Yes"
       << "\n";
}
void no() {
  cout << "No"
       << "\n";
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
struct FAIL {
  FAIL() {
    cout << "CHANGE!!!"
         << "\n";
  }
};
struct Z {
  int number;
  string data;
  int is_sample;
  int operator==(const Z &other) const {
    return make_tuple(number, data, is_sample) ==
           make_tuple(other.number, other.data, other.is_sample);
  }
};
int get(const string &x, int n) {
  if (x[0] == '0' && x.size() > 1) {
    return -1;
  }
  int res = 0;
  for (int i = (0); i < (x.size()); ++i) {
    res *= 10;
    if (!('0' <= x[i] && x[i] <= '9')) {
      return -1;
    }
    res += x[i] - '0';
  }
  if (!(1 <= res && res <= n)) {
    return -1;
  }
  return res;
}
Z BAD = {-2, "", -2};
int main() {
  srand(12);
  int n;
  cin >> n;
  vector<Z> v(n);
  int samples = 0;
  for (int i = (0); i < (n); ++i) {
    cin >> v[i].data >> v[i].is_sample;
    v[i].number = get(v[i].data, n);
    samples += v[i].is_sample;
  }
  vector<Z> used(n + 1, BAD);
  vector<Z> other;
  int flag = 0;
  for (int i = (0); i < (n); ++i) {
    if (v[i].number != -1) {
      used[v[i].number] = v[i];
    } else {
      other.push_back(v[i]);
      flag = 1;
    }
  }
  vector<pair<string, string>> res;
  int j = 1;
  int k = samples + 1;
  while (j <= samples) {
    while (j <= samples && !(used[j] == BAD)) {
      ++j;
    }
    while (k <= n && used[k].is_sample != 1) {
      ++k;
    }
    if (j <= samples && k <= n) {
      res.push_back({to_string(k), to_string(j)});
      swap(used[j], used[k]);
    }
    ++j;
    ++k;
  }
  j = 1;
  k = samples + 1;
  while (j <= samples) {
    while (j <= samples && used[j].is_sample != 0) {
      ++j;
    }
    while (k <= n && !(used[k] == BAD)) {
      ++k;
    }
    if (j <= samples && k <= n) {
      res.push_back({to_string(j), to_string(k)});
      swap(used[j], used[k]);
    }
    ++j;
    ++k;
  }
  j = 1;
  k = samples + 1;
  while (other.size() > 1) {
    if (other.back().is_sample == 1) {
      while (j <= samples && !(used[j] == BAD)) {
        ++j;
      }
      assert(j != samples + 1);
      res.push_back({other.back().data, to_string(j)});
      used[j] = other.back();
      other.pop_back();
    } else {
      while (k <= n && !(used[k] == BAD)) {
        ++k;
      }
      assert(k != n + 1);
      res.push_back({other.back().data, to_string(k)});
      used[k] = other.back();
      other.pop_back();
    }
  }
  int f = 0;
  int free_mem = -1;
  if (!flag) {
    for (int i = (1); i < (n + 1); ++i) {
      if (((i <= samples) ^ used[i].is_sample)) {
        v[i].number = -1;
        v[i].data = "a";
        other.push_back(v[i]);
        used[i] = BAD;
        res.push_back({to_string(i), "a"});
        f = 1;
        free_mem = i;
        break;
      }
    }
    if (!f) {
      cout << 0;
      return 0;
    }
  } else {
    for (int i = (1); i < (n + 1); ++i) {
      if (used[i] == BAD) {
        free_mem = i;
        break;
      }
    }
  }
  j = 1;
  k = samples + 1;
  while (1) {
    if (free_mem <= samples) {
      while (k <= n && used[k].is_sample != 1) {
        ++k;
      }
      if (k == n + 1) {
        res.push_back({other.back().data, to_string(free_mem)});
        used[free_mem] = other.back();
        other.pop_back();
        break;
      } else {
        res.push_back({to_string(k), to_string(free_mem)});
        swap(used[k], used[free_mem]);
        free_mem = k;
      }
    } else {
      while (j <= samples && used[j].is_sample != 0) {
        ++j;
      }
      if (j == samples + 1) {
        res.push_back({other.back().data, to_string(free_mem)});
        used[free_mem] = other.back();
        other.pop_back();
        break;
      } else {
        res.push_back({to_string(j), to_string(free_mem)});
        swap(used[j], used[free_mem]);
        free_mem = j;
      }
    }
  }
  cout << res.size() << "\n";
  for (int i = (0); i < (res.size()); ++i) {
    cout << "move " << res[i].first << " " << res[i].second << "\n";
  }
  return 0;
}
