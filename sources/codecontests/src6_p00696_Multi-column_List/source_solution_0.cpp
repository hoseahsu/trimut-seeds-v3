# 2 "1115.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>


namespace solution {
    using namespace std;

    typedef istringstream ISS;
    typedef ostringstream OSS;
    typedef vector<string> VS;
    typedef long long LL;
    typedef int INT;
    typedef vector<INT> VI;
    typedef vector<VI> VVI;
    typedef pair<INT, INT> II;

    const int SIZE = 101;
    const int WORD_MAX = 1001;
    int n;
    int m;
    int w;
    int p;
    string S[WORD_MAX];
    int si;
    string T[SIZE][SIZE];
    int pi;
    int ti;

    class Solution {
    private:
        void init() {
        }

        int get_number() {
            string line;
            getline( cin, line );
            ISS iss( line );
            int res;
            iss >> res;
            return res;
        }

        bool input() {
            n = get_number();
            if ( n == 0 ) return false;
            m = get_number();
            w = get_number();
            p = get_number();

            string line;
            si = 0;
            while ( getline( cin, line ) ) {
                if ( line == "?" ) break;
                S[si ++] = line;
            }
            return true;
        }

        void add_item( string s ) {
            int len = s.size();
            if ( len > w ) {
                for ( int i = 0; i < len; ) {
                    string t = s.substr( i, w );
                    add_item(t);
                    i += w;
                }
            } else {
                int r = ti % n;
                int c = ti / n;

                for ( int i = 0; i < len; ++ i ) {
                    T[pi][r][i+w*c+p*c] = s[i];
                }

                ti ++;
                if ( ti >= n * m ) {
                    ti = 0;
                    pi ++;
                }
            }
        }

        void solve() {
            pi = 0;
            ti = 0;
            for ( int i = 0; i < SIZE; ++ i ) {
                for ( int j = 0; j < n; ++ j ) {
                    T[i][j] = string( m * w + p * ( m - 1 ), '.' );
                }
            }

            for ( int i = 0; i < si; ++ i ) {
                string word = S[i];
                add_item(word);
            }
        }

        void output() {
            for ( int i = 0; i <= pi; ++ i ) {
                if ( i == pi && ti == 0 ) {
                    continue;
                }
                for ( int j = 0; j < n; ++ j ) {
                    cout << T[i][j] << endl;
                }
                cout << "#" << endl;
            }
            cout << "?" << endl;
        }

    public:
        int run() {
            while ( init(), input() ) {
                solve();
                output();
            }
            return 0;
        }
    };
}

int main() {
    using namespace solution;
    Solution s;
    return s.run();
}