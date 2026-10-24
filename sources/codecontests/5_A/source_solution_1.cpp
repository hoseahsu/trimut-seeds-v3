#include <bits/stdc++.h>
using namespace std;
int main() {
  char newMess[501];
  int countText = 0;
  int countPeople = 0;
  while (cin.get(newMess, 501, '\n')) {
    if (newMess[0] == '\n' && newMess[1] == '\n')
      break;
    else if (newMess[0] == '+')
      countPeople++;
    else if (newMess[0] == '-')
      countPeople--;
    else {
      int i = 0;
      while (newMess[i] != ':') i++;
      countText += countPeople * (strlen(newMess) - i - 1);
    }
    cin.get();
  }
  cout << countText;
}
