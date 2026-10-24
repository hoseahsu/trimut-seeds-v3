#include <bits/stdc++.h>
const int INF = 1e4 + 7;
using namespace std;
int bg[6];
int ed[6];
int vas[5];
int pet[5];
int solv[5];
int wrong[5];
bool checkd(int a, int b, int p, int q) { return a * q < p * b; }
int main() {
  int cur = 1;
  for (int i = 0; i < 6; i++) {
    ed[i] = cur;
    cur *= 2;
    bg[i] = cur;
  }
  bg[5] = INF;
  int n;
  cin >> n;
  for (int i = 0; i < 5; i++) {
    cin >> vas[i];
    int t = vas[i];
    if (t == -1) {
      wrong[i] += 1;
    } else {
      solv[i] += 1;
    }
  }
  for (int i = 0; i < 5; i++) {
    cin >> pet[i];
    int t = pet[i];
    if (t == -1) {
      wrong[i] += 1;
    } else {
      solv[i] += 1;
    }
  }
  for (int i = 2; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int t;
      cin >> t;
      if (t == -1) {
        wrong[j] += 1;
      } else {
        solv[j] += 1;
      }
    }
  }
  for (int curans = 0; curans < (int)1e6; curans++) {
    int ansv = 0;
    int ansp = 0;
    for (int j = 0; j < 5; j++) {
      int cost;
      int pass = solv[j];
      int fail = wrong[j];
      if ((vas[j] != -1) and (pet[j] != -1) and (vas[j] > pet[j])) {
        pass += curans;
      } else {
        fail += curans;
      }
      if (checkd(1, 2, pass, fail + pass)) {
        cost = 500;
      } else if (checkd(1, 4, pass, fail + pass)) {
        cost = 1000;
      } else if (checkd(1, 8, pass, fail + pass)) {
        cost = 1500;
      } else if (checkd(1, 16, pass, fail + pass)) {
        cost = 2000;
      } else if (checkd(1, 32, pass, fail + pass)) {
        cost = 2500;
      } else {
        cost = 3000;
      }
      if (vas[j] != -1) {
        ansv += cost - cost / 250 * vas[j];
      }
      if (pet[j] != -1) {
        ansp += cost - cost / 250 * pet[j];
      }
    }
    if (ansv > ansp) {
      cout << curans;
      return 0;
    }
  }
  cout << -1 << endl;
}
