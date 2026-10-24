#include <bits/stdc++.h>
long long int MAX(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
using namespace std;
long long int MIN(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
int OneD(int row, int col, int t_n_o_r) { return row * t_n_o_r + col; }
long long int MOD(long long int a, long long int b) {
  return a >= 0 ? a % b : (b - abs(a % b)) % b;
}
void MN(int &a, int b) {
  if (a > b) a = b;
}
void MX(int &a, int b) {
  if (a < b) a = b;
}
int X[] = {1, 0, -1, 0, 1, -1, -1, 1};
int Y[] = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> w8s, ans, used0, used1;
int size, m;
bool staahhp = false;
void bt(int done, int tot0, int tot1, int di) {
  if (staahhp) return;
  if (done == m) {
    staahhp = true;
    printf("YES\n");
    for (int x = 0; x < m; x++) printf("%d ", ans[x]);
    printf("\n");
    return;
  }
  for (int i = 0; i < size && !staahhp; i++) {
    if (di) {
      if (tot1 + w8s[i] > tot0 && !used0[i] && !staahhp) {
        used1[i]++;
        ans.push_back(w8s[i]);
        bt(done + 1, tot0, tot1 + w8s[i], 0);
        ans.pop_back();
        used1[i]--;
      }
    } else {
      if (tot0 + w8s[i] > tot1 && !used1[i] && !staahhp) {
        used0[i]++;
        ans.push_back(w8s[i]);
        bt(done + 1, tot0 + w8s[i], tot1, 1);
        ans.pop_back();
        used0[i]--;
      }
    }
  }
}
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < 10; i++) {
    if (str[i] == '1') {
      w8s.push_back(i + 1);
      used0.push_back(0);
      used1.push_back(0);
    }
  }
  size = w8s.size();
  scanf("%d", &m);
  bt(0, 0, 0, 0);
  if (!staahhp) printf("NO\n");
  return 0;
}
