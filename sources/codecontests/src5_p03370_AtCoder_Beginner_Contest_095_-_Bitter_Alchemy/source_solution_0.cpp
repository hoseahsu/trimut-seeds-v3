#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,X;
  cin >> N >> X;
  vector<int> m(N);
  int M = 100000;
  for (int i = 0; i < N; i++){
    cin >> m[i];
    X -= m[i];
    M = min(M,m[i]);
  }
  cout << N + X / M;
}