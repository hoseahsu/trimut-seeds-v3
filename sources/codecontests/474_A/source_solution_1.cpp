#include <bits/stdc++.h>
using namespace std;
char s1[105], s[10];
char ss[205][3];
int main() {
  string s2, s3, s4;
  while (scanf("%s", s) != EOF) {
    scanf("%s", s1);
    s2 = "qwertyuiop";
    s3 = "asdfghjkl;";
    s4 = "zxcvbnm,./";
    int len1 = s2.length();
    for (int i = 1; i < len1; i++) {
      ss[s2[0] - 32][1] = s2[1];
      ss[s2[i] - 32][1] = s2[i + 1];
      ss[s2[i] - 32][0] = s2[i - 1];
    }
    len1 = s3.length();
    for (int i = 1; i < len1; i++) {
      ss[s3[0] - 32][1] = s3[1];
      ss[s3[i] - 32][1] = s3[i + 1];
      ss[s3[i] - 32][0] = s3[i - 1];
    }
    len1 = s4.length();
    for (int i = 1; i < len1; i++) {
      ss[s4[0] - 32][1] = s4[1];
      ss[s4[i] - 32][1] = s4[i + 1];
      ss[s4[i] - 32][0] = s4[i - 1];
    }
    if (s[0] == 'R') {
      for (int i = 0; i < strlen(s1); i++) {
        cout << ss[s1[i] - 32][0];
      }
      printf("\n");
    } else {
      for (int i = 0; i < strlen(s1); i++) {
        cout << ss[s1[i] - 32][1];
      }
      printf("\n");
    }
  }
  return 0;
}
