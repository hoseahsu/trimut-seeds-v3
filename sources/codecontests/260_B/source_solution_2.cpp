#include <bits/stdc++.h>
using namespace std;
void gt(int &a, int b) {
  if (a < b) a = b;
}
string n2s(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}
int days[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isValidDate(string str) {
  int d, m, y;
  char ch;
  for (int i = 0; i <= 8; i++) {
    if (i == 2 || i == 5) {
      if (str[i] != '-') return false;
      continue;
    }
    if (!isdigit(str[i])) return false;
  }
  stringstream ss;
  ss << str;
  ss >> d >> ch >> m >> ch >> y;
  if (y < 2013 || y > 2015) return false;
  if (m < 1 || m > 12) return false;
  return d <= days[m] && d > 0;
}
map<string, int> m;
int main() {
  string str, temp, ans = "";
  int max = 0;
  cin >> str;
  for (int i = 0; i <= str.length() - 10; i++) {
    temp = str.substr(i, 10);
    if (isValidDate(temp)) {
      if (m.find(temp) == m.end()) {
        m[temp] = 1;
      } else {
        m[temp]++;
      }
    }
  }
  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
    if (max < it->second) {
      ans = it->first;
      max = it->second;
    }
  }
  cout << ans << endl;
  return 0;
}
