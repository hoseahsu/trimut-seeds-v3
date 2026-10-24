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

int h, w, n;
vector<string> grid;

class Data
{
public:
    vector<int> p;
    bitset<3> bs;
    Data(vector<int>& p0, bitset<3> bs0){
        p = p0;
        bs = bs0;
    }
    int toInt(){
        int ret = bs.to_ulong();
        for(int i=0; i<n; ++i){
            ret *= h * w;
            ret += p[i];
        }
        return ret;
    }
};

int solve()
{
    string gridLine = accumulate(grid.begin(), grid.end(), string());
    int diff[] = {1, -1, w, -w};

    vector<int> sp(n), gp(n);
    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            int c = grid[i][j];
            if('a' <= c && c <= 'c'){
                sp[c-'a'] = i * w + j;
            }else if('A' <= c && c <= 'C'){
                gp[c-'A'] = i * w + j;
            }
        }
    }

    int size = 1 << n;
    for(int i=0; i<n; ++i)
        size *= h * w;

    vector<vector<bool> > check(2, vector<bool>(size, false));
    check[0][Data(sp, 0).toInt()] = true;
    check[1][Data(gp, 0).toInt()] = true;
    vector<deque<Data> > dq(2);
    dq[0].push_back(Data(sp, 0));
    dq[1].push_back(Data(gp, 0));

    int turn = 0;
    int m = 1;
    int ret = 1;
    for(;;){
        if(m == 0){
            ++ ret;
            turn ^= 1;
            m = dq[turn].size();
        }

        Data d = dq[turn].front();
        dq[turn].pop_front();
        -- m;

        for(int i=0; i<n; ++i){
            if(d.bs[i])
                continue;
            d.bs[i] = true;
            for(int j=0; j<4; ++j){
                d.p[i] += diff[j];

                bool ok = true;
                if(gridLine[d.p[i]] == '#')
                    ok = false;
                for(int k=0; k<n; ++k){
                    if(k != i && d.p[k] == d.p[i])
                        ok = false;
                }

                if(ok){
                    int a = d.toInt();
                    if(!check[turn][a]){
                        dq[turn].push_front(d);
                        ++ m;
                        check[turn][a] = true;
                    }
                }

                d.p[i] -= diff[j];
            }
            d.bs[i] = false;
        }

        d.bs = 0;
        int a = d.toInt();
        if(!check[turn][a]){
            if(check[turn^1][a])
                return ret;
            dq[turn].push_back(d);
            check[turn][a] = true;
        }
    }
}

int main()
{
    for(;;){
        cin >> w >> h >> n;
        if(w == 0)
            return 0;
        cin.ignore();

        grid.resize(h);
        for(int i=0; i<h; ++i)
            getline(cin, grid[i]);

        cout << solve() << endl;
    }
}