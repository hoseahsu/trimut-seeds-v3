#include <bits/stdc++.h>
using namespace std;
bool X[1000001], vis[1000001];
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> V;
    int x;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      X[x] = true;
      V.push_back(x);
    }
    deque<int> Q;
    for (int i = 1; i < 1000001; i++)
      if (!X[i] && !X[1000001 - i]) Q.push_front(i), Q.push_back(1000001 - i);
    printf("%d\n", n);
    for (int i = 0; i < V.size(); i++) {
      if (vis[V[i]]) continue;
      if (!X[1000001 - V[i]])
        printf("%d\n", 1000001 - V[i]);
      else {
        printf("%d %d\n", Q.front(), Q.back());
        vis[1000001 - V[i]] = true;
        Q.pop_front();
        Q.pop_back();
      }
    }
  }
}
