#include <iostream>
#include <string>
using namespace std;
int main(void){
  int i;
  string n;
  cin >> n;
  for (i=1;i<n.size();i++) if (n[i]!='9') break;
  if (i==n.size()) cout << n[0]-'0'+9*(n.size()-1) << endl;
  else cout << n[0]-'0'-1+9*(n.size()-1) << endl;
  return 0;
}