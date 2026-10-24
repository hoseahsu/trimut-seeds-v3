#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

int main()
{
    int h, w, x, y;
    cin>>h>>w>>x>>y;
    if ((h*w)%2==1 && (x+y)%2==1) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}

