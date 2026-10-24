#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long n;
  cin >> n;
  vector<long long> a, b;
  long long sum1 = 0, sum2 = 0;
  long long temp = n / 4;
  long long r = n;
  for (long long i = 0; i < temp; i++) {
    a.push_back(r - 1);
    a.push_back(r - 2);
    b.push_back(r);
    b.push_back(r - 3);
    r = r - 4;
  }
  temp = n % 4;
  if (temp == 1) {
    a.push_back(1);
  }
  if (temp == 2) {
    a.push_back(1), b.push_back(2);
  }
  if (temp == 3) {
    a.push_back(1), a.push_back(2), b.push_back(3);
  }
  long long s1 = 0, s2 = 0;
  for (long long i = 0; i < a.size(); i++) s1 += a[i];
  for (long long i = 0; i < b.size(); i++) s2 += b[i];
  cout << abs(s1 - s2) << "\n" << a.size() << " ";
  for (long long i = 0; i < a.size(); i++) cout << a[i] << " ";
}
