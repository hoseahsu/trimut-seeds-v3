#include <iostream>
#include <algorithm>
using namespace std;

const int H = 8;
const int W = 5;
string s;
char G[H][W];

int main() {
  while(cin >> s) {
    while(s.size() != W) s.insert(0, "0");
    for(int i = 0; i < W; ++i) {
      int n = s[i]-'0';
      string t = "**=*****";
      t[1-n/5] = t[3+n%5] = ' ';
      for(int j = 0; j < H; ++j) {
        G[j][i] = t[j];
      }
    }
    static bool first = true;
    if(first) first = false;
    else cout << endl;
    for(int i = 0; i < H; ++i) {
      for(int j = 0; j < W; ++j) {
        cout << G[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}