#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, t[100], i, ans=0, f=0;
    string s[100], x;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> s[i] >> t[i];
    }
    cin >> x;
    for(i=0;i<n;i++){
        if(f==1) ans+=t[i];
        if(s[i]==x) f=1;
    }
    cout << ans <<endl;
    

    return 0;
}
