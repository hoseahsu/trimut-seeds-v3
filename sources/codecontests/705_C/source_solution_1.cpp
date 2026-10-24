#include <bits/stdc++.h>
using namespace std;
const int Max = 3e5 + 1;
int Cnt[Max], Read[Max];
int main() {
  int n, q, start = 0;
  long long unread = 0;
  vector<int> Notifications;
  cin >> n >> q;
  while (q--) {
    int type, x;
    cin >> type >> x;
    if (type == 1) {
      Cnt[x]++;
      unread++;
      Notifications.push_back(x);
    } else if (type == 2) {
      unread -= Cnt[x];
      Cnt[x] = 0;
      Read[x] = Notifications.size();
    } else {
      for (; start < x; ++start) {
        if (Cnt[Notifications[start]] && Read[Notifications[start]] <= start) {
          Cnt[Notifications[start]]--;
          unread--;
        }
      }
    }
    cout << unread << endl;
  }
  return 0;
}
