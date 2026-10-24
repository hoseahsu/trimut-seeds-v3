#include <bits/stdc++.h>
using namespace std;
template <class htpe, class cmp>
using heap = priority_queue<htpe, vector<htpe>, cmp>;
template <class htpe>
using min_heap = heap<htpe, greater<htpe> >;
template <class htpe>
using max_heap = heap<htpe, less<htpe> >;
const int INF = 1791791791;
const long long INFLL = 1791791791791791791ll;
template <int input_buf_size, int output_buf_size>
class FastIO {
  char cbuf[input_buf_size + 1];
  int icur = 0;
  inline bool go_to_next_token() {
    while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
    while (cbuf[icur] == 0) {
      icur = 0;
      if (fgets(cbuf, sizeof(cbuf), stdin) != cbuf) return false;
      while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
    }
    return true;
  }

 public:
  string readString() {
    assert(go_to_next_token());
    string ans;
    while (cbuf[icur] != ' ' && cbuf[icur] != '\n' && cbuf[icur] != 0)
      ans.push_back(cbuf[icur++]);
    ans.shrink_to_fit();
    return ans;
  }
  template <class int_type>
  int_type readInt() {
    assert(go_to_next_token());
    int_type x = 0;
    bool m = cbuf[icur] == '-';
    if (m) icur++;
    while ('0' <= cbuf[icur] && cbuf[icur] <= '9') {
      x *= 10;
      x += (cbuf[icur] - '0');
      icur++;
    }
    if (m) x = -x;
    return x;
  }
  bool seekEof() { return !go_to_next_token(); }

 private:
  char obuf[output_buf_size + 1];
  int ocur = 0;
  inline void write_string(const char *str, size_t sz = 0) {
    if (sz == 0) sz = strlen(str);
    if (ocur + sz > output_buf_size) {
      fputs(obuf, stdout);
      fputs(str, stdout);
      ocur = 0;
      obuf[0] = 0;
      return;
    }
    strcpy(obuf + ocur, str);
    ocur += sz;
    obuf[ocur] = 0;
  }

 public:
  template <class int_type>
  void writeInt(int_type x, bool sp = true) {
    char buf[21];
    int c = 0;
    if (x < 0) {
      buf[c++] = '-';
      x = -x;
    }
    int s = c;
    if (x == 0) {
      buf[c++] = '0';
    }
    while (x > 0) {
      buf[c++] = (x % 10) + '0';
      x /= 10;
    }
    for (int i = 0; 2 * i < c - s; i++) {
      swap(buf[s + i], buf[c - 1 - i]);
    }
    buf[c] = 0;
    write_string(buf, c);
    if (sp) write_string(" ", 1);
  }
  void writeString(string s, bool space = true) {
    write_string(s.c_str(), s.size());
    if (space) write_string(" ", 1);
  }
  void writeEndl() { write_string("\n", 1); }
  void flush() {
    fputs(obuf, stdout);
    ocur = 0;
    obuf[0] = 0;
  }

 private:
  bool lflush;

 public:
  FastIO(bool local_flush) {
    obuf[0] = 0;
    lflush = local_flush;
  }
  ~FastIO() { fputs(obuf, stdout); }
};
FastIO<10000000, 10000000> IO(true);
int n, clast;
vector<string> by_idx;
map<string, int> idx;
void add_string(string s) {
  if (idx.count(s))
    return;
  else {
    by_idx.push_back(s);
    idx[s] = clast++;
  }
}
mt19937 rnd(179);
string gen_random() {
  uniform_int_distribution<int> dist('a', 'z');
  string ans;
  for (int i = 0; i < ((int)(6)); ++i) ans.push_back(dist(rnd));
  return ans;
}
string not_in_set() {
  string t = gen_random();
  while (idx.count(t)) t = gen_random();
  return t;
}
string to_str(int x) {
  char s[10];
  sprintf(s, "%d", x);
  return s;
}
map<string, bool> ws_to;
int main() {
  n = IO.readInt<int>();
  for (int i = 0; i < ((int)(n)); ++i) add_string(to_str(i + 1));
  vector<pair<string, bool> > inp;
  for (int i = 0; i < ((int)(n)); ++i) {
    string s = IO.readString();
    add_string(s);
    bool b = IO.readInt<int>();
    inp.push_back(make_pair(s, b));
    ws_to[s] = b;
  }
  string w = not_in_set();
  add_string(w);
  vector<int> who(n);
  vector<bool> filled(clast);
  for (int i = 0; i < ((int)(n)); ++i) {
    filled[idx[inp[i].first]] = true;
    if (idx[inp[i].first] < n) who[idx[inp[i].first]] = i;
  }
  int numf = 0;
  for (int i = 0; i < ((int)(n)); ++i) numf += inp[i].second;
  vector<bool> ok(n);
  for (int i = 0; i < ((int)(n)); ++i) {
    if (idx[inp[i].first] < numf && inp[i].second) ok[idx[inp[i].first]] = true;
    if (numf <= idx[inp[i].first] && idx[inp[i].first] < n && !inp[i].second)
      ok[idx[inp[i].first]] = true;
  }
  vector<int> wanted;
  vector<pair<string, string> > ans;
  int bucket = -1;
  for (int i = 0; i < ((int)(n)); ++i) {
    if (!filled[i]) bucket = i;
    if (filled[i] && !ok[i]) wanted.push_back(i);
  }
  if (bucket == -1) {
    auto it = find((ok).begin(), (ok).end(), false);
    if (it == ok.end()) {
      IO.writeInt(0);
      IO.writeEndl();
      return 0;
    }
    bucket = it - ok.begin();
    ans.push_back(make_pair(by_idx[bucket], w));
    filled[bucket] = false;
    filled.back() = true;
    wanted.erase(find((wanted).begin(), (wanted).end(), bucket));
    ws_to[w] = ws_to[by_idx[bucket]];
  }
  queue<int> wfa, wfb;
  for (int u : wanted) {
    if (u < numf)
      wfa.push(u);
    else
      wfb.push(u);
  }
  while (wfa.size() && wfb.size()) {
    int a;
    if (bucket < numf) {
      a = wfb.front();
      wfb.pop();
    } else {
      a = wfa.front();
      wfa.pop();
    }
    ans.push_back(make_pair(by_idx[a], by_idx[bucket]));
    filled[bucket] = true;
    filled[a] = false;
    bucket = a;
  }
  queue<int> free_a;
  queue<int> free_b;
  for (int i = 0; i < ((int)(numf)); ++i)
    if (!filled[i]) free_a.push(i);
  for (int i = (int)(numf); i < ((int)(n)); ++i)
    if (!filled[i]) free_b.push(i);
  while (wfa.size()) {
    int a = wfa.front();
    wfa.pop();
    int b = free_b.front();
    free_b.pop();
    ans.push_back(make_pair(by_idx[a], by_idx[b]));
    filled[a] = false;
    filled[b] = true;
  }
  while (wfb.size()) {
    int a = wfb.front();
    wfb.pop();
    int b = free_a.front();
    free_a.pop();
    ans.push_back(make_pair(by_idx[a], by_idx[b]));
    filled[a] = false;
    filled[b] = true;
  }
  free_a = queue<int>();
  free_b = queue<int>();
  for (int i = 0; i < ((int)(numf)); ++i)
    if (!filled[i]) free_a.push(i);
  for (int i = (int)(numf); i < ((int)(n)); ++i)
    if (!filled[i]) free_b.push(i);
  for (int i = (int)(n); i < ((int)(clast)); ++i) {
    if (filled[i]) {
      int a;
      if (ws_to[by_idx[i]]) {
        a = free_a.front();
        free_a.pop();
      } else {
        a = free_b.front();
        free_b.pop();
      }
      ans.push_back(make_pair(by_idx[i], by_idx[a]));
      filled[i] = false;
      filled[a] = true;
    }
  }
  IO.writeInt(ans.size(), 0);
  IO.writeEndl();
  for (auto p : ans) {
    IO.writeString("move");
    IO.writeString(p.first);
    IO.writeString(p.second, 0);
    IO.writeEndl();
  }
  return 0;
}
