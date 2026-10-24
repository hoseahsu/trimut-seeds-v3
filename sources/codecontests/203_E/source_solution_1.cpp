#include <bits/stdc++.h>
using namespace std;
struct Robot {
  long long c, f;
  bool operator<(const Robot& rob) const { return f < rob.f; }
};
long long n, d, S, x;
vector<Robot> carry, nocarry;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> d >> S;
  for (int i = 0; i < n; ++i) {
    Robot rob;
    cin >> rob.c >> rob.f >> x;
    if (x < d) rob.f = 0x3f3f3f3f;
    if (rob.c == 0)
      nocarry.push_back(rob);
    else
      carry.push_back(rob);
  }
  sort(carry.begin(), carry.end());
  sort(nocarry.begin(), nocarry.end());
  long long numR = 0, fuel = 0;
  while (numR < nocarry.size() && fuel + nocarry[numR].f <= S)
    fuel += nocarry[numR++].f;
  if (!carry.empty() && carry[0].f <= S) {
    long long numR2 = 0, fuel2 = carry[0].f, compart = 0;
    for (int i = 0; i < carry.size(); ++i) compart += carry[i].c;
    for (int i = 1; i < carry.size(); ++i) nocarry.push_back(carry[i]);
    sort(nocarry.begin(), nocarry.end());
    while (numR2 + compart < nocarry.size() && fuel2 + nocarry[numR2].f <= S)
      fuel2 += nocarry[numR2++].f;
    numR2 = 1 + min(numR2 + compart, (long long)nocarry.size());
    if (numR2 > numR || (numR2 == numR && fuel2 < fuel))
      numR = numR2, fuel = fuel2;
  }
  cout << numR << ' ' << fuel << endl;
}
