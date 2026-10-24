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

int main()
{
    for(;;){
        string s;
        if(!(cin >> s))
            return 0;

        int n = s.size();
        s = '+' + s.substr(0, n-1);

        int i = 0;
        int a = 0;
        bool error = false;
        while(i < n){
            int j = i+1;
            int b = 0;
            while(j < n && isdigit(s[j])){
                b *= 10;
                b += s[j] - '0';
                ++ j;
            }
            if(j - i > 5)
                error = true;

            if(s[i] == '+')
                a += b;
            else if(s[i] == '-')
                a -= b;
            else
                a *= b;
            if(a < 0 || a > 9999)
                error = true;

            i = j;
        }

        if(error)
            cout << "E" << endl;
        else
            cout << a << endl;
    }
}