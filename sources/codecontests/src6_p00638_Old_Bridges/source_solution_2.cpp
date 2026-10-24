#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <list>
#include <cmath>
#include <map>
#include <utility>

#define _USE_MATH_DEFINES
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define INF 999999999
#define atcoder 1000000007
#define MAX_N 100

using namespace std;

int main() {

	int n, num1, num2, V;
	vector< pair <int, int> > treasure(25);
	bool judge ;

	while (cin >> n, n) {
		judge = true;
		V = 0;

		REP(i, n) {
			cin >> num1 >> num2;
			treasure[i] = make_pair(num2, num1);
		}

		sort(treasure.begin(), treasure.begin() + n);

		REP(i, n) {
			V += treasure[i].second;
			if (V > treasure[i].first) {
				judge = false;
				break;
			}
		}

		if (judge == true) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}

		REP(i, n) {
			treasure[i] = make_pair(0, 0);
		}

	}

	return 0;
}