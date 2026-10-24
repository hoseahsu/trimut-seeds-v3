#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  string a, b;
  cin >> a >> b;

  for(int i = 0 ; i <= a.size() - b.size() ; i++ ){
    bool flag = false;
    for(int j = 0 ; j < b.size() ; j++ ){
      if(a[i + j] != b[j] && b[j] != '_') flag = true;
    }
    if(!flag){
      cout << "Yes" << endl;
      exit(0);
    }
  }
  cout << "No" << endl;
}
