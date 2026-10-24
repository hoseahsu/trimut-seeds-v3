#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    mp.erase(mp.begin(), mp.end());
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      mp[a]++;
    }
    long long cnt = mp.size();
    if (cnt != 1 && k == 1)
      cout << "-1" << endl;
    else if (cnt == 1 && k == 1)
      cout << "1" << endl;
    else if (cnt <= k)
      cout << "1" << endl;
    else {
      if ((cnt - k) % (k - 1) == 0)
        cnt = 1 + (cnt - k) / (k - 1);
      else
        cnt = 2 + (cnt - k) / (k - 1);
      cout << cnt << endl;
    }
  }
}
