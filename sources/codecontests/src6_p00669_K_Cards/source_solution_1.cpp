#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 101;

int n,k,t;
vector<int> c;

int judge(){
  int max_ = -1<<28;
  for(int i = 0 ; i <= n - k ; i++){
    t = 1;
    for(int j = i ; j < i + k ; j++){
      t *= c[j];
    }
    max_ = max(max_,t);
  }
  return max_;
}

int main(){

  while(cin >> n >> k , n){
    int in;
    c.clear();

    for(int i = 0 ; i < n ; i++){
      cin >> in;
      c.push_back(in);
    }

    int tmx = judge() ,smx = -1<<28;
   

    for(int i = 0 ; i < n ; i++){
      for(int j = i + 1 ; j < n ; j++){
	swap(c[i],c[j]);
	smx = max(smx,judge());
	swap(c[i],c[j]);
      }
    }

    if(tmx > smx) cout << "NO GAME" << endl;
    else cout << smx - tmx << endl;
  }

  return 0;
}