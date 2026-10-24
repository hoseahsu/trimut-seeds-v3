#include <bits/stdc++.h>
using namespace std;
int main() {
  string arr[12] = {"C",  "C#", "D",  "D#", "E", "F",
                    "F#", "G",  "G#", "A",  "B", "H"};
  int arr1[3];
  string arr2[3];
  cin >> arr2[0] >> arr2[1] >> arr2[2];
  int temp = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 12; j++) {
      if (arr2[i] == arr[j]) {
        arr1[i] = j;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arr1[j] > arr1[j + 1]) {
        temp = arr1[j];
        arr1[j] = arr1[j + 1];
        arr1[j + 1] = temp;
      }
    }
  }
  if (arr1[1] - arr1[0] == 3 && arr1[2] - arr1[1] == 4 ||
      arr1[0] + 12 - arr1[2] == 3 && arr1[1] - arr1[0] == 4 ||
      arr1[2] - arr1[1] == 3 && arr1[0] + 12 - arr1[2] == 4)
    cout << "minor" << endl;
  else if (arr1[1] - arr1[0] == 4 && arr1[2] - arr1[1] == 3 ||
           arr1[0] + 12 - arr1[2] == 4 && arr1[1] - arr1[0] == 3 ||
           arr1[2] - arr1[1] == 4 && arr1[0] + 12 - arr1[2] == 3)
    cout << "major" << endl;
  else
    cout << "strange" << endl;
  return 0;
}
