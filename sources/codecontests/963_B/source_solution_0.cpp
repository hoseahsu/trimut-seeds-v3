#include <bits/stdc++.h>
using namespace std;
const int maxn = ((int)2e5) + 5;
vector<int> adj[maxn];
vector<int> del[maxn];
int INDEX = 0;
bool onStack[maxn];
int index_[maxn], lowLink[maxn];
stack<int> stk;
vector<vector<int> > components;
void getConnectedComponent(int i);
void getConnectedComponent(int i) {
  index_[i] = INDEX;
  lowLink[i] = INDEX;
  INDEX++;
  stk.push(i);
  onStack[i] = true;
  for (int nxt : adj[i]) {
    if (index_[nxt] == -1) {
      getConnectedComponent(nxt);
      lowLink[i] = min(lowLink[i], lowLink[nxt]);
    } else if (onStack[nxt]) {
      lowLink[i] = min(lowLink[i], index_[nxt]);
    }
  }
  if (lowLink[i] == index_[i]) {
    vector<int> comp;
    int poped;
    do {
      poped = stk.top();
      stk.pop();
      onStack[poped] = false;
      comp.push_back(poped);
    } while (poped != i);
    if (comp.size() > 0) {
      components.push_back(comp);
    }
  }
}
void tarjan(int n) {
  memset(onStack, false, sizeof(onStack));
  fill(index_, index_ + n, -1);
  for (int i = 0; i < n; i++) {
    if (index_[i] == -1) {
      getConnectedComponent(i);
    }
  }
}
int dfs(int curr, int par = -1) {
  int mustDel = 0;
  for (int nxt : del[curr]) {
    if (nxt != par) {
      mustDel += dfs(nxt, curr);
    }
  }
  if (par == -1) {
    if (mustDel & 1)
      return 1;
    else
      return 0;
  }
  if (mustDel % 2 == 0) {
    adj[par].push_back(curr);
    return 1;
  } else {
    adj[curr].push_back(par);
    return 0;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    int x;
    cin >> x;
    x--;
    if (x == -1) continue;
    del[x].push_back(i - 1);
    del[i - 1].push_back(x);
  }
  if (dfs(0) == 1) {
    cout << "NO";
  } else {
    cout << "YES\n";
    tarjan(n);
    reverse(components.begin(), components.end());
    for (vector<int> comp : components) {
      cout << comp[0] + 1 << endl;
    }
    tarjan(n);
  }
}
