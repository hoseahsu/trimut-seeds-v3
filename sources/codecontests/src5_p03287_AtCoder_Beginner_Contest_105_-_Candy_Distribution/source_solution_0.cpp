#include <iostream>
#include <map>

using namespace std;

int main()
{
  uint64_t n, m;
  cin >> n >> m;
  map<uint64_t, uint64_t> mp;
  mp[0] = 1;
  uint64_t accumulate = 0;
  uint64_t ans = 0;
  for (auto i = 0; i < n; i++) {
    uint64_t v;
    cin >> v;
    accumulate += v;
    ans += mp[accumulate % m]++;
  }
  cout << ans << endl;
}
