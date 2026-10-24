#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

// const P {
//   string s[10];
// };

// const operator<(const P& a, const P &b) {
//   REP(i,5) {
//     a[i]
//   }
// }

int main() {
  string s[10];
  while(cin>>s[0],s[0]!="END") {
    REP(i,9)
      cin >> s[i+1];
    REP(i,10) {                 // ñÎÌÌàÌðs[0]@Æ·éB
      string t = s[i];
      reverse(ALL(t));
      if (s[i] != t) {
        swap(s[0],s[i]);
        break;
      }
    }
    string hoge = "1000002345";
    int res = 0, hogehoge = 0;  // hogehoge ÍãºÌ¾ªêv·éàÌÌd¡JEgðñð·é½ß
    
    do {
      if (hoge[0] > '3') break;
      if (hoge[0] == '3' && hoge[1] >= '3') continue;
      vector<string>vv(5);
      bool used[10];
      REP(i,10) {
        if (hoge[i]!='0') {
          vv[hoge[i]-'1'] = s[i];
          used[i] = 1;
        }else
          used[i] = 0;
      }
      REP(S, 1<<5) {
        if (S>>(hoge[0]-'1') & 1) continue;
        vector<string> v = vv;
        bool dame = 0;
        REP(i,5) {
          if (S>>i & 1) {
            reverse(ALL(v[i]));
            if (v[i] == vv[i]) {
              dame = 1;break;
            }
          }
        }
        if (dame) continue;
        bool f = 1;
        bool used2[10];
        memcpy(used2, used, sizeof(used));
        REP(i,5) {
          string tmp;
          REP(j,5) {
            if (v[j][i] == '0')
              tmp += '1';
            else
              tmp += '0';
          }
          string tmp2 = tmp;
          reverse(ALL(tmp2));
          bool ff = 0;
          REP(j,10) {
            if (!used2[j] && (tmp == s[j] || tmp2 == s[j])) {
              used2[j] = 1;
              ff = 1;
              break;
            }
          }
          if (!ff) {
            f = 0;
            break;
          }
        }
        if (f) {
          if (hoge[0] == '3' && hoge[1] == '0') hogehoge++;
          else res++;
          // cout << hoge << endl;
          // cout << bitset<5>(S) << endl;
          // FOR(it, v)
          //   cout << *it << " ";
          // cout << endl;
        }
      }
    } while(next_permutation(ALL(hoge)));
    cout << res + hogehoge/2 << endl;
  }
}