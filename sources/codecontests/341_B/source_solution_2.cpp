#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const long long MAXLL = 0x0FFFFFFFFFFFFFFFll;
const int MAXINT = 0x0FFFFFFF;
const int MAXN = 100005;
int n;
int a[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  set<int> st;
  set<int>::iterator it;
  st.clear();
  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
    it = st.find(a[i]);
    it++;
    if (it != st.end()) st.erase(it);
  }
  cout << st.size() << endl;
  return 0;
}
