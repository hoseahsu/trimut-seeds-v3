#include <bits/stdc++.h>
using namespace std;
void passe(int i, int &bleu, int &rouge) {
  int a = (i + 1) / 2;
  int b = i / 2;
  bleu = a * a + b * b;
  rouge = a * b + a * b;
}
int main() {
  int n;
  cin >> n;
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    if (b == "soft")
      ++c1;
    else
      ++c2;
  }
  for (int i = 1;; ++i) {
    int bleu, rouge;
    passe(i, bleu, rouge);
    if (bleu >= max(c1, c2) && rouge >= min(c1, c2)) {
      cout << i << "\n";
      return 0;
    }
  }
}
