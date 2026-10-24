#include <bits/stdc++.h>
using namespace std;
int n, numone, numtwo, sum, tmp;
char nlong;
string nameone, nametwo;
string read;
struct node {
  string name;
  int goal, moregoal, score;
  int q;
} wxy[100];
bool check(int t) {
  for (int i = 0; i < tmp; i++)
    if (wxy[t].name[i] != nameone[i]) return false;
  return true;
}
bool checktwo(int t) {
  for (int i = tmp + 1; i < sum; i++)
    if (wxy[t].name[i - tmp - 1] != nametwo[i - tmp - 1]) return false;
  return true;
}
bool cmpfirst(node a, node b) {
  if (a.score > b.score) return 1;
  if (a.score < b.score) return 0;
  if (a.moregoal > b.moregoal) return 1;
  if (a.moregoal < b.moregoal) return 0;
  if (a.goal > b.goal) return 1;
  return 0;
}
bool cmplast(node a, node b) { return a.name < b.name; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> wxy[i].name;
    wxy[i].q = wxy[i].name.size();
  }
  for (int j = 1; j <= n * (n - 1) / 2; j++) {
    sum = 0;
    tmp = 0;
    nameone = "", nametwo = "";
    numone = numtwo = 0;
    while (1) {
      scanf("%c", &nlong);
      if (nlong == '-')
        break;
      else if ((nlong >= 'a' && nlong <= 'z') ||
               (nlong >= 'A' && nlong <= 'Z')) {
        nameone += nlong;
        sum++;
      }
    }
    tmp = sum;
    sum++;
    while (1) {
      scanf("%c", &nlong);
      if (nlong == ' ')
        break;
      else {
        nametwo += nlong;
        sum++;
      }
    }
    while (1) {
      scanf("%c", &nlong);
      if (nlong == ':')
        break;
      else if (nlong >= '0' && nlong <= '9')
        numone = numone * 10 + nlong - '0';
    }
    cin >> numtwo;
    int one, two;
    for (int i = 1; i <= n; i++)
      if (wxy[i].q == tmp)
        if (check(i)) {
          one = i;
          break;
        }
    for (int i = 1; i <= n; i++)
      if (wxy[i].q + tmp + 1 == sum)
        if (checktwo(i)) {
          two = i;
          break;
        }
    wxy[one].goal += numone;
    wxy[two].goal += numtwo;
    wxy[one].moregoal += numone - numtwo;
    wxy[two].moregoal += numtwo - numone;
    if (numone > numtwo)
      wxy[one].score += 3;
    else if (numtwo > numone)
      wxy[two].score += 3;
    else {
      wxy[one].score++;
      wxy[two].score++;
    }
  }
  sort(wxy + 1, wxy + n + 1, cmpfirst);
  sort(wxy + 1, wxy + (n) / 2 + 1, cmplast);
  for (int i = 1; i <= n / 2; i++) cout << wxy[i].name << endl;
  return 0;
}
