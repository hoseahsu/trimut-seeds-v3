#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(long long i=0;i<n;++i)
#define REPR(i,n) for(long long i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair
#define SV(v) {for(long long sitr=0;sitr<v.size();++sitr){cin>>v[sitr];}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

int main(){

  string s1, s2;
  cin >> s1 >> s2;

  int len1 = s1.length();

  string s_odd = "", s_even = "";
  REP(i,len1){
    if(i % 2 == 0){
      s_odd = s_odd + s1[i];
    }else{
      s_even = s_even + s1[i];
    }
  }

  int pos1=0, pos2=0;
  bool f = true;
  REP(i, len1){
    if(i % 2 == 0){
      if(s1.substr(pos1, len1-pos1).find(s1[i]) != string::npos){
        pos1 = s1.substr(pos1, len1-pos1).find(s1[i])+1+pos1;
      }else{
        f = false;
        break;
      }
    }else{
       if(s2.substr(pos2, len1-pos2).find(s1[i]) != string::npos){
        pos2 = s2.substr(pos2, len1-pos2).find(s1[i])+1+pos2;
      }else{
        f = false;
        break;
      }   
    }
  }
  if(f){
    cout << "Yes\n";
    return 0;
  }

  pos1=0; pos2=0;
  f = true;
  REP(i, len1){
    if(i % 2 != 0){
      if(s1.substr(pos1, len1-pos1).find(s1[i]) != string::npos){
        pos1 = s1.substr(pos1, len1-pos1).find(s1[i])+1+pos1;
      }else{
        f = false;
        break;
      }
    }else{
       if(s2.substr(pos2, len1-pos2).find(s1[i]) != string::npos){
        pos2 = s2.substr(pos2, len1-pos2).find(s1[i])+1+pos2;
      }else{
        f = false;
        break;
      }   
    }
  }

  if(f){
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }
  return 0;
}


