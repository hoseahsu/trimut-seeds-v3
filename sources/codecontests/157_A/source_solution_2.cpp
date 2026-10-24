#include <bits/stdc++.h>
using namespace std;
int cal[1000][1000];
int k[1000];
int main() {
  int a;
  cin >> a;
  int sum = 0;
  for (int i = 0; i < a; i++) {
    sum = 0;
    for (int j = 0; j < a; j++) {
      cin >> cal[i][j];
      sum += cal[i][j];
    }
    k[i] = sum;
  }
  int count = 0;
  for (int i = 0; i < a; i++) {
    sum = 0;
    for (int j = 0; j < a; j++) {
      sum += cal[j][i];
    }
    for (int s = 0; s < a; s++)
      if (sum > k[s]) ++count;
  }
  cout << count << endl;
  return 0;
}
