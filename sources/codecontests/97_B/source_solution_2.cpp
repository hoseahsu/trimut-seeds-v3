#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int n;
set<pair<int, int> > added;
vector<pair<int, int> > inp;
void conquer(const vector<pair<int, int> >& inp) {
  if (inp.size() == 2) {
    if (inp[0].first != inp[1].first && inp[0].second != inp[1].second)
      added.insert({inp[0].first, inp[1].second});
    return;
  } else if (inp.size() <= 1)
    return;
  vector<pair<int, int> > nxt;
  const int tar = inp.size() >> 1;
  int ind = 0;
  while (true) {
    int pind = ind;
    auto p = inp[ind];
    int cx = p.first;
    while (ind < inp.size() && inp[ind].first == cx) ind++;
    int c1 = pind;
    int c2 = inp.size() - ind;
    if (c1 <= tar && c2 <= tar) {
      nxt.resize(c1);
      for (int i = 0; i < c1; i++)
        nxt[i] = inp[i], added.emplace(cx, inp[i].second);
      conquer(nxt);
      nxt.resize(c2);
      for (int i = ind; i < inp.size(); i++)
        nxt[i - ind] = inp[i], added.emplace(cx, inp[i].second);
      conquer(nxt);
      break;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    inp.emplace_back(a, b);
  }
  sort(inp.begin(), inp.end());
  conquer(inp);
  for (int i = 0; i < inp.size(); i++) added.insert(inp[i]);
  printf("%d\n", added.size());
  for (auto x : added) printf("%d %d\n", x.first, x.second);
}
