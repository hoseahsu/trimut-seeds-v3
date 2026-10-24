#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    while(cin >> n, n) {
        vector<string> v(n);
        for(int i=0; i<n; ++i) {
            cin >> v[i];
        }
        int ans = 0;
        for(int i=1; i<v.size(); ++i) {
            if((v[i-1] == "lu" && v[i] == "ru") || (v[i-1] == "ru" && v[i] == "lu") ||
               (v[i-1] == "rd" && v[i] == "ld") || (v[i-1] == "ld" && v[i] == "rd")) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
