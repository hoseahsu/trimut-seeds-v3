#include <iostream>
#include <vector>
#include <utility>
using namespace std;

long long input(){
  string s;
  cin >> s;
  long long a = 0;
  size_t i = 0;
  for(;i < s.length(); ++i){
    if(s[i] == '.') break;
    a *= 10;
    a += s[i]-'0';
  }
  ++i;
  for(size_t j = 0; j < 9; ++j){
    a *= 10;
    if(i+j < s.length())
      a += s[i+j]-'0';
  }
  return a;
}

int main(){
  int N;
  cin >> N;
  long long ans = 0;
  const int m = 60, M = 2*m+1;
  vector<vector<long long>> C(M,vector<long long>(M));
  
  for(int i = 0; i < N; ++i){
    long long a = input();
    int c2 = -9, c5 = -9;
    // cerr << a << endl;
    while(a%2 == 0) ++c2, a /= 2;
    while(a%5 == 0) ++c5, a /= 5;
    // cerr << c2 << " " << c5 << endl;
    c2 = min(c2,M-1);
    c5 = min(c5,M-1);
    for(int i = -c2+m; i < M; ++i){
      for(int j = -c5+m; j < M; ++j){
        ans += C[i][j];
      }
    }

    ++C[c2+m][c5+m];
  }
  cout << ans << endl;
}
