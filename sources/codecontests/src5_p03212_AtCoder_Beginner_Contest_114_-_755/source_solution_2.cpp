#include <bits/stdc++.h>

using namespace std;

int n;

int dfs(long x=0, int a=0, int b=0, int c=0)
{
  if (x > n) return 0;
  int res = a*b*c;
  x *= 10;
  res += dfs(x+3, 1, b, c);
  res += dfs(x+5, a, 1, c);
  res += dfs(x+7, a, b, 1);
  return res;
}

int main()
{
  cin >> n;
  cout << dfs() << endl;
}