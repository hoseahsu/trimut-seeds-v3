#include <iostream>
#include <map>
using namespace std;
int n, m, mx;
string s[105], t;
map<string, int> mp;
int main()
{
    int i;
    cin>>n;
    for(i=0; i<n; i++) cin>>s[i], mp[s[i]]++;
    cin>>m;
    while(m--) cin>>t, mp[t]--;
    for(i=0; i<n; i++) mx = max(mx, mp[s[i]]);
    cout<<mx;
    return 0;
}