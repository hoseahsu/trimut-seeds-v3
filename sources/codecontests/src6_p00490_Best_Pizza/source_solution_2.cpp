#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, A, B, C, D[101];
  cin >> N;
  cin >> A >> B >> C;
  for(int i = 0; i < N; i++) cin >> D[i];
  sort(D, D + N, greater<int>());
  for(int i = 1; i < N; i++) D[i] += D[i-1];
  int maxical = C / A;
  for(int i = 0; i < N; i++) maxical = max(maxical, (C + D[i])/(A + (i+1)*B));
  cout << maxical << endl;
  return 0;
}