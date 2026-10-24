#include <bits/stdc++.h>
using namespace std;
map<string, int> chords;
int main() {
  string input[3];
  string result[3], str;
  int i, j, k, diff1, diff2, first, second, third, res = 0;
  chords.insert(make_pair("C", 1));
  chords.insert(make_pair("C#", 2));
  chords.insert(make_pair("D", 3));
  chords.insert(make_pair("D#", 4));
  chords.insert(make_pair("E", 5));
  chords.insert(make_pair("F", 6));
  chords.insert(make_pair("F#", 7));
  chords.insert(make_pair("G", 8));
  chords.insert(make_pair("G#", 9));
  chords.insert(make_pair("A", 10));
  chords.insert(make_pair("B", 11));
  chords.insert(make_pair("H", 12));
  for (i = 0; i < 3; i++) cin >> input[i];
  for (i = 0; i < 3; i++) {
    result[0] = input[i];
    for (j = 0; j < 3; j++) {
      if (j == i) continue;
      result[1] = input[j];
      for (k = 0; k < 3; k++) {
        if (k == i || k == j) continue;
        result[2] = input[k];
        first = chords[result[0]];
        second = chords[result[1]];
        third = chords[result[2]];
        diff1 = second - first;
        diff2 = third - second;
        if (diff1 < 0) diff1 += 12;
        if (diff2 < 0) diff2 += 12;
        if (diff1 == 4 && diff2 == 3) {
          res = 1;
          break;
        }
        if (diff1 == 3 && diff2 == 4) {
          res = 2;
          break;
        }
      }
    }
  }
  if (res == 1) cout << "major";
  if (res == 2) cout << "minor";
  if (res == 0) cout << "strange";
}
