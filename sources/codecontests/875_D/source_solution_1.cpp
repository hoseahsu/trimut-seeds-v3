#include <bits/stdc++.h>
using namespace std;
vector<int> B;
int d[200000][100];
map<pair<int, int>, int> K;
void RMQ_init(const vector<int> &A) {
  int n = A.size();
  for (int i = 0; i < n; i++) d[i][0] = A[i];
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 0; i + (1 << j) - 1 < n; i++)
      d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}
int RMQ(int L, int R) {
  int k = 0;
  while ((1 << (k + 1)) <= R - L + 1) k++;
  return max(d[L][k], d[R - (1 << k) + 1][k]);
}
int checkst(int low, int high, vector<int> &A, int aim) {
  while (low < high) {
    int mid = (low + high) / 2 + 1;
    if (A[mid] > aim) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  return A[low];
}
int checked(int low, int high, vector<int> &A, int aim) {
  while (low < high) {
    int mid = (low + high) / 2;
    if (A[mid] < aim) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return A[low];
}
int checkfrom(int st, int from, int ends) {
  while (from < ends) {
    int mid = (from + ends) / 2;
    if (RMQ(mid, st) <= B[st]) {
      ends = mid;
    } else {
      from = mid + 1;
    }
  }
  return from;
}
int checkbehind(int st, int from, int ends) {
  while (from < ends) {
    int mid = (from + ends) / 2 + 1;
    if (RMQ(st, mid) <= B[st]) {
      from = mid;
    } else {
      ends = mid - 1;
    }
  }
  return from;
}
int main() {
  int n;
  cin >> n;
  vector<int> A[100];
  int d;
  K.clear();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d);
    B.push_back(d);
  }
  RMQ_init(B);
  for (int i = 0; i < n; i++) {
    int c = B[i];
    int n = 1;
    while (c) {
      int v = c % 2;
      if (v) {
        A[n].push_back(i);
      }
      n++;
      c = c / 2;
    }
  }
  vector<pair<int, int> > D;
  for (int i = 0; i < n; i++) {
    int from = checkfrom(i, 0, i);
    int behind = checkbehind(i, i, n - 1);
    D.push_back(make_pair(from, behind));
  }
  long long sum = 0;
  int k = n;
  for (int i = 0; i < n; i++) {
    int G = B[i];
    int n = 1;
    int mins = -1;
    int maxs = 20000000;
    while (G) {
      int v = G % 2;
      if (v == 0) {
        if (A[n].size() > 0) {
          int f = checkst(0, A[n].size() - 1, A[n], i);
          int e = k - 1;
          e = checked(0, A[n].size() - 1, A[n], i);
          if (e > i) {
            maxs = min(maxs, e);
          }
          if (f < i) {
            mins = max(mins, f);
          }
        }
      }
      n++;
      G = G / 2;
    }
    int g = D[i].first;
    if (K[make_pair(D[i].first, D[i].second)])
      D[i].first = K[make_pair(D[i].first, D[i].second)];
    if (maxs == 20000000) {
      maxs = D[i].second + 1;
    }
    if (mins == -1) {
      mins = D[i].first - 1;
    }
    long long fr = 0;
    long long be = 0;
    if (D[i].first <= mins)
      fr = mins - D[i].first + 1;
    else
      fr = 0;
    if (D[i].second >= maxs)
      be = D[i].second - maxs + 1;
    else
      be = 0;
    sum =
        sum + be * (i - D[i].first + 1) + fr * (D[i].second - i + 1) - fr * be;
    K[make_pair(g, D[i].second)] = i + 1;
  }
  cout << sum << endl;
  return 0;
}
