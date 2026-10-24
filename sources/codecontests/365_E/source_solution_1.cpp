#include <bits/stdc++.h>
using namespace std;
const int maxN = (5100);
bool isp[maxN * maxN / 100];
int chanta[maxN];
vector<long long> Ps, ans;
set<long long> nums;
int main() {
  long long k, now = 1, i = 0, limit;
  ios::sync_with_stdio(0);
  cin >> k;
  limit = k * k * 2;
  isp[1] = 1;
  for (int i = 1; i < maxN; i++)
    if (!isp[i]) {
      for (int j = i + i; j < maxN * 50; j += i) isp[j] = 1;
      Ps.push_back(i);
    }
  for (int i = maxN; i < maxN * 50; i++)
    if (!isp[i]) Ps.push_back(i);
  while (ans.size() < k) {
    long long tav = Ps[i];
    ans.push_back(tav);
    for (int z = 0; z < ans.size(); z++)
      if (ans[z] * Ps[i] <= limit) ans.push_back(ans[z] * Ps[i]);
    sort(ans.begin(), ans.end());
    i++;
    if (i > Ps.size())
      cout << Ps.size() / (Ps.size() / (Ps.size() + 1)) << endl;
  }
  for (int z = ans.size() - k; z < ans.size(); z++) {
    long long now = ans[z];
    for (int j = 0; j <= i; j++)
      while (now && now % Ps[j] == 0) {
        now /= Ps[j];
        chanta[j]++;
      }
  }
  for (int j = 0; j <= i; j++)
    if (chanta[j])
      if (chanta[j] < k / 2)
        cout << "badbakht shodim :(( " << endl
             << " : " << k / (k / (k + 1)) << endl;
  for (int i = ans.size() - k; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  cin >> k;
}
