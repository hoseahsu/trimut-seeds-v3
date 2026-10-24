#include <bits/stdc++.h>
using namespace std;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, -1, 1, -1};
int main() {
  int noTest;
  cin >> noTest;
  while (noTest--) {
    int size, end;
    string word;
    cin >> size;
    cin >> word;
    end = size - 1;
    bool valid = true;
    for (int i = 0; i < (size / 2); i++) {
      if (word[i] != word[end]) {
        if (word[i] > 'a' && word[i] < 'z')
          if (((word[i] - 1 == word[end] - 1) ||
               (word[i] - 1 == word[end] + 1)) ||
              ((word[i] + 1 == word[end] - 1) ||
               (word[i] + 1 == word[end] + 1))) {
            end--;
            continue;
          } else {
            valid = false;
            break;
          }
        else if (word[i] == 'a')
          if (((word[i] + 1 == word[end] - 1) ||
               (word[i] + 1 == word[end] + 1))) {
            end--;
            continue;
          } else {
            valid = false;
            break;
          }
        else if (((word[i] - 1 == word[end] - 1) ||
                  (word[i] - 1 == word[end] + 1))) {
          end--;
          continue;
        } else {
          valid = false;
          break;
        }
      }
      end--;
    }
    puts(valid ? "YES" : "NO");
  }
}
