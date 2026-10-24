#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    cout << h*w-(h/a)*(w/b)*a*b << endl;
    return 0;
}

