#include<iostream>

using namespace std;

int main(){
  int n;
  string s;
  char prev;
  bool yes_or_no;
  cin >> n;
  while(n-- > 0){
    cin >> s;
    prev = s[0];
    yes_or_no = true;
    for(int i=1;i<s.length();i++){
      if(prev == s[i]){
	yes_or_no = false;
	break;
      }
	prev = s[i];
    }
    if(yes_or_no)cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}