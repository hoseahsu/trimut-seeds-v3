#include <bits/stdc++.h>
using namespace std;
int b[8], l[8], n, A;
double mata(int soma) { return (double)A / (double)(A + soma); }
double calc() {
  double ans = 0;
  int precisa = (n / 2) + 1;
  double tot = 0;
  int ss = 0;
  for (int i = 0; i < (int)(n); i++) ss += b[i];
  for (int i = 0; i < (int)((1 << n)); i++) {
    double prob = 1.0;
    int mentem = 0;
    int soma = 0;
    for (int j = 0; j < (int)(n); j++) {
      if (i & (1 << j)) {
        mentem++;
        prob *= (100 - l[j]) / 100.0;
        soma += b[j];
      } else {
        prob *= (l[j] / 100.0);
      }
    }
    int verd = n - mentem;
    tot += prob;
    if (verd < precisa) {
      prob *= mata(soma);
      ans += (prob);
    } else {
      ans += prob;
    }
  }
  ans /= tot;
  return ans;
}
double usa_candy(int at, int k) {
  if (at == n) {
    int ok = 1;
    for (int i = 0; i < (int)(n); i++)
      if (l[i] < 100) ok = 0;
    if (ok) k = 0;
    if (k) return 0;
    return calc();
  }
  double a = usa_candy(at + 1, k), b = a;
  if (l[at] < 100 && k) {
    l[at] += 10;
    b = usa_candy(at, k - 1);
    l[at] -= 10;
  }
  return max(a, b);
}
int main() {
  int k;
  cin >> n >> k >> A;
  for (int i = 0; i < (int)(n); i++) {
    cin >> b[i] >> l[i];
  }
  double ans = usa_candy(0, k);
  cout << setprecision(10);
  cout << fixed << ans << endl;
  return 0;
}
