#include <iostream>
#include <string>

using namespace std;

typedef long long int lli;

string str = "01235789";

void func(lli n)
{
  if(n == 0) return;
  func(n/8);
  cout << str[n%8];
}

int main()
{
  lli n;

  while(cin>>n && n){
    func(n);
    cout << endl;
  }

  return 0;
}