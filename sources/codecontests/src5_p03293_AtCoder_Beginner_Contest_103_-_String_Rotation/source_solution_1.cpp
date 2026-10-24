#include <iostream>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 0, sz = (int) s.size(); i < sz; i++) {
    if (s.substr(i) + s.substr(0, i) == t) {
      cout << "Yes";
      return 0;
    }
  } 
  cout << "No";
  return 0;
}