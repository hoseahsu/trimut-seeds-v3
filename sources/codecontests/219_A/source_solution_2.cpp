#include <bits/stdc++.h>
using namespace std;
int main() {
  int k = 0;
  cin >> k;
  string input = "";
  cin >> input;
  std::sort(input.begin(), input.end());
  char run_char = input.at(0);
  int count = 1;
  string rep_string = "";
  bool quit = false;
  for (int i = 1; i < input.length(); i++) {
    if (input.at(i) == run_char) {
      count++;
    } else {
      if (count % k == 0) {
        int num = count / k;
        for (int j = 0; j < num; j++) {
          rep_string += run_char;
        }
        count = 1;
        run_char = input.at(i);
      } else {
        cout << -1;
        quit = true;
        break;
      }
    }
  }
  if (!quit) {
    if (count % k == 0) {
      int num = count / k;
      for (int i = 0; i < num; i++) {
        rep_string += input.at(input.length() - 1);
      }
      string k_string = "";
      for (int i = 0; i < k; i++) {
        k_string += rep_string;
      }
      cout << k_string;
    } else
      cout << -1;
  }
  return 0;
}
