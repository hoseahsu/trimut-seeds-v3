#include <bits/stdc++.h>
using namespace std;
int main() {
  string message, word, original;
  int n = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> word;
    original += "<3";
    original += word;
  }
  original += "<3";
  cin >> message;
  int j = 0;
  string tmp;
  for (int i = 0; i < (int)message.size(); i++) {
    if (j == (int)original.size()) {
      break;
    }
    if (message[i] == original[j]) {
      tmp += message[i];
      j++;
    }
  }
  if (tmp == original) {
    cout << "yes";
    return 0;
  }
  cout << "no";
  return 0;
}
