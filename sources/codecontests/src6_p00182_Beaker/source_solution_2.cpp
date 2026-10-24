#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
 
typedef long long LL;
typedef set <LL> SET;
 
const int size = 51;
const string YES = "YES";
const string NO = "NO";

int bek[size];
int vol[size];
int n;

SET visited[size];
 
bool dist( int now );
bool solve( int now );
 
bool dist( int now ) {
    if ( vol[now] == 0 ) return solve( now + 1 );

    LL state = 0;
    for ( LL i = now; i < n; ++ i ) {
        state <<= 1;
        if ( vol[i] == bek[i] ) state ++;
    }
    
    if ( visited[now].find( state ) != visited[now].end() ) return false;
    visited[now].insert( state );
    if ( vol[now] == 0 ) return false;
    
    for ( int i = now + 1; i < n; ++ i ) {
        if ( vol[i] != 0 ) continue;
        if ( vol[now] < bek[i] ) continue;
        if ( i - 1 >= now + 1 && bek[i-1] == bek[i] && vol[i-1] == 0 ) continue;
        vol[now] -= bek[i];
        vol[i] = bek[i];
        if ( dist( now ) ) return true;
        vol[i] = 0;
        vol[now] += bek[i];
    }
    return false;
}
 
bool solve( int now ) {
    if ( now == n ) return true;
    if ( vol[now] == 0 ) return false;
    if ( solve( now + 1 ) ) return true;
    if ( dist( now ) ) return true;
    return false;
}
 
int main() {
    while ( cin >> n && n ) {
        for ( int i = 0; i < n; ++ i ) {
            cin >> bek[i];
            vol[i] = 0;
            visited[i].clear();
        }
        sort( bek, bek + n, greater<int>() );
        vol[0] = bek[0];
        cout << ( solve( 0 ) ? YES : NO ) << endl;
    }
    return 0;
}