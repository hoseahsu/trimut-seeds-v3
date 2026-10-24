#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 myrand(seed);
uniform_int_distribution<long long> dist(0, 5);
long long read() {
  long long x = 0, flag = 0;
  char ch = getchar();
  if (ch == '-') flag = 1;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x *= 10, x += ch - '0', ch = getchar();
  if (flag) return -x;
  return x;
}
long long power(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum *= a;
    sum %= mod;
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return sum % mod;
  ;
}
int a[100010];
class point {
 public:
  int x, y;
};
vector<point> aa;
queue<int> q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int i;
  int num = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) num++;
  }
  int now = n - num;
  int ans = 0;
  int last = 0;
  int last2 = 0;
  int flag = 0;
  int flag2 = 0;
  int flag4 = 0;
  for (i = n; i >= 1; i--) {
    if (a[i] == 1) {
      if (flag == 0) {
        ans++;
        point temp;
        temp.x = now;
        temp.y = i;
        aa.push_back(temp);
        flag = now;
        flag4 = i;
        now--;
        continue;
      }
      ans++;
      point temp;
      temp.x = now;
      temp.y = i;
      aa.push_back(temp);
      q.push(now);
      now--;
    } else if (a[i] == 2) {
      if (!flag) {
        cout << -1;
        return 0;
      } else {
        if (flag2 == 0) {
          flag2 = 1;
          point temp;
          ans += 1;
          temp.x = flag;
          temp.y = i;
          aa.push_back(temp);
        } else {
          if (q.empty()) {
            cout << -1;
            return 0;
          } else {
            int temp = q.front();
            q.pop();
            point temp2;
            ans++;
            temp2.x = temp;
            temp2.y = i;
            aa.push_back(temp2);
          }
        }
      }
      last2 = i;
      now--;
    } else if (a[i] == 3) {
      if (last == 0) {
        if (!last2) {
          if (!flag) {
            cout << -1;
            return 0;
          }
          point temp;
          temp.x = now;
          temp.y = i;
          aa.push_back(temp);
          temp.x = now;
          temp.y = flag4;
          aa.push_back(temp);
          flag2 = 1;
          ans += 2;
          last = i;
        } else {
          point temp;
          temp.x = now;
          temp.y = i;
          aa.push_back(temp);
          temp.x = now;
          temp.y = last2;
          aa.push_back(temp);
          ans += 2;
          last = i;
        }
      } else {
        point temp;
        temp.x = now;
        temp.y = i;
        aa.push_back(temp);
        temp.x = now;
        temp.y = last;
        aa.push_back(temp);
        ans += 2;
        last = i;
      }
      now--;
    }
  }
  cout << ans << endl;
  for (i = 0; i <= ans - 1; i++) cout << aa[i].x << " " << aa[i].y << endl;
}
