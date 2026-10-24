#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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
#include <functional>
using namespace std;

const long long INF = LLONG_MAX / 4;

int q;
vector<string> s(1);
vector<vector<int> > to;
vector<long long> len;

void solve(long long a, long long b)
{
    stack<pair<int, int> > stk;
    stk.push(make_pair(0, 0));

    for(;;){
        int i = stk.top().first;
        int j = stk.top().second;
        stk.pop();

        while(j < (int)s[i].size()){
            int next = to[i][s[i][j]-'a'];
            if(next == -1){
                if(a <= 0)
                    cout << s[i][j];
                -- a;
                -- b;
            }else{
                if(a < len[next]){
                    stk.push(make_pair(i, j+1));
                    stk.push(make_pair(next, 0));
                    break;
                }else{
                    a -= len[next];
                    b -= len[next];
                }
            }
            if(b < 0){
                cout << endl;
                return;
            }
            ++ j;
        }
    }
}

int main()
{
    long long a, b;
    cin >> s[0] >> q >> a >> b;

    ++ q;
    s.resize(q);
    vector<char> c(q);
    for(int i=1; i<q; ++i){
        cin >> c[i] >> s[i];
        if(s[i] == ".")
            s[i] = "";
    }

    to.assign(q, vector<int>(26, -1));
    len.resize(q, 0);
    for(int i=q-1; i>=0; --i){
        for(unsigned j=0; j<s[i].size(); ++j){
            int next = to[i][s[i][j]-'a'];
            if(next == -1){
                ++ len[i];
            }else if(len[next] > 0){
                len[i] += len[next];
            }else{
                s[i].erase(s[i].begin() + j);
                -- j;
            }
            len[i] = min(len[i], INF);
        }

        if(i > 0){
            to[i-1] = to[i];
            if(s[i].size() == 1 && to[i][s[i][0]-'a'] != -1)
                to[i-1][c[i]-'a'] = to[i][s[i][0]-'a'];
            else
                to[i-1][c[i]-'a'] = i;
        }
    }

    if(b > len[0])
        cout << "." << endl;
    else
        solve(a-1, b-1);

    return 0;
}