#include <cstdio>
#include <cstdlib>
#include <vector>

const int N = 100000 + 10;

int n;
std::vector<int> adj[N];

void fail() {
  puts("First");
  exit(0);
}

bool dfs(int a, int fa = -1) {
  int cnt = 0;
  for (auto b : adj[a]) if (b != fa) cnt += dfs(b, a);
  if (cnt > 1) fail();
  return !cnt;
}

int main() {
  scanf("%d", &n);
  if (n & 1) fail();
  for (int i = n - 1; i--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  puts("Second");
  return 0;
}
