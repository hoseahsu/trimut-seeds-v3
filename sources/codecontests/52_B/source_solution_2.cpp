#include <bits/stdc++.h>
using namespace std;
long long Set(long long N, long long pos) { return N = N | (1 << pos); }
long long reset(long long N, long long pos) { return N = N & ~(1 << pos); }
bool check(long long N, long long pos) { return (bool)(N & (1 << pos)); }
void CI(long long &_x) { scanf("%d", &_x); }
void CO(long long &_x) { cout << _x; }
template <typename T>
void getarray(T a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void prLLIarray(T a[], long long n) {
  for (long long i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const long long INF = 0x7f7f7f7f;
long long dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
long long dr4[4] = {0, 0, 1, -1};
long long dc4[4] = {-1, 1, 0, 0};
long long kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
char grid[1005][1005];
long long row_L[1005][1005];
long long row_R[1005][1005];
long long col_L[1005][1005];
long long col_R[1005][1005];
int main() {
  vector<pair<long long, long long> > V;
  long long r, c;
  cin >> r >> c;
  for (long long i = 0; i < r; i++)
    for (long long j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  long long cnt = 0;
  for (long long i = 0; i < r; i++)
    if (grid[i][0] == '*') col_L[i][0] = 1;
  for (long long i = 0; i < r; i++) {
    for (long long j = 1; j < c; j++) {
      if (grid[i][j] == '*') col_L[i][j] = 1;
      col_L[i][j] += col_L[i][j - 1];
    }
    for (long long j = c - 1; j >= 0; j--) {
      if (grid[i][j] == '*') col_R[i][j] = 1;
      col_R[i][j] += col_R[i][j + 1];
    }
  }
  for (long long i = 0; i < c; i++) {
    if (grid[0][i] == '*') row_L[0][i] = 1;
  }
  for (long long j = 0; j < c; j++) {
    for (long long i = 1; i < r; i++) {
      if (grid[i][j] == '*') row_L[i][j] = 1;
      row_L[i][j] += row_L[i - 1][j];
    }
    for (long long i = r - 1; i >= 0; i--) {
      if (grid[i][j] == '*') row_R[i][j] = 1;
      row_R[i][j] += row_R[i + 1][j];
    }
  }
  for (long long i = 0; i < r; i++)
    for (long long j = 0; j < c; j++)
      if (grid[i][j] == '*') {
        row_L[i][j]--;
        row_R[i][j]--;
        col_L[i][j]--;
        col_R[i][j]--;
        cnt += (row_L[i][j]) * (col_L[i][j] + col_R[i][j]);
        cnt += (row_R[i][j]) * (col_L[i][j] + col_R[i][j]);
      }
  cout << cnt << "\n";
}
