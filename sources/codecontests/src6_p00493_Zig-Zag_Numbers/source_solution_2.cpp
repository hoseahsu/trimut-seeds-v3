#include <cstdio>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

const int MOD = 10000;

int solve(string s, int m)
{
    int n = s.size();

    vector<vector<vector<vector<int> > > > dp1(n+1, vector<vector<vector<int> > >(10, vector<vector<int> >(2, vector<int>(m, 0))));
    vector<vector<vector<vector<int> > > > dp2(n+1, vector<vector<vector<int> > >(10, vector<vector<int> >(2, vector<int>(m, 0))));

    for(int i=0; i<n; ++i){
        for(int x=1; x<=9; ++x){
            if(i == 0 && x > s[0] - '0')
                continue;
            if(i == 0 && x == s[0] - '0'){
                dp1[i+1][x][0][x%m] = 1;
                if(i < n-1)
                    dp2[i+1][x][0][x%m] = 1;
            }else{
                dp1[i+1][x][1][x%m] = 1;
                if(i < n-1)
                    dp2[i+1][x][1][x%m] = 1;
            }
        }

        for(int x=0; x<=9; ++x){
            for(int j=0; j<2; ++j){
                for(int rest=0; rest<m; ++rest){
                    for(int y=0; y<=9; ++y){
                        if(j == 0 && y > s[i] - '0')
                            continue;
                        if(y == x)
                            continue;

                        int k = (j == 1 || y < s[i] - '0')? 1:0;
                        int rest1 = (rest * 10 + y) % m;
                        if((i % 2 == 0) ^ (y > x)){
                            dp1[i+1][y][k][rest1] += dp1[i][x][j][rest];
                            dp1[i+1][y][k][rest1] %= MOD;
                        }else{
                            dp2[i+1][y][k][rest1] += dp2[i][x][j][rest];
                            dp2[i+1][y][k][rest1] %= MOD;
                        }

                    }
                }
            }
        }
    }

    int ret = 0;
    for(int i=0; i<=9; ++i){
        for(int j=0; j<2; ++j){
            ret += dp1[n][i][j][0] + dp2[n][i][j][0];
        }
    }
    ret %= MOD;

    return ret;
}

int main()
{
    string a, b;
    int m;
    cin >> a >> b >> m;

    for(int i=a.size()-1; ; --i){
        if(a[i] > '0'){
            -- a[i];
            break;
        }
        a[i] = '9';
    }

    int ret = solve(b, m) - solve(a, m);
    ret = (ret % MOD + MOD) % MOD;
    cout << ret << endl;

    return 0;
}