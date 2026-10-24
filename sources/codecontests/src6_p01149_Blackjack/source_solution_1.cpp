#include <iostream>
#include <memory>
#include <memory.h>
#include <cmath>
#include <fstream>
#include <cmath>
#include <numeric>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <iomanip>
#include <list>
#include <cctype>
#include <algorithm>
#define USE_MATH_DEFINES
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<int, PP> PPP;
const int INF = 1 << 30;
const double EPS = 1E-9;

int to_num(char c){
	if(isdigit(c)){
		return c - '0';
	}else if(c == 'T'){
		return 10;
	}else if(c == 'J'){
		return 10;
	}else if(c == 'Q'){
		return 10;
	}else if(c == 'K'){
		return 10;
	}else{
		return 1;
	}
}


int card[8];

int main(){
	int n;
	char ch;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		bool ele_used = false;

		cin >> ch;
		a = to_num(ch);
		cin >> ch;
		b = to_num(ch);

		for(int j = 0; j < 8; j++){
			cin >> ch;
			card[j] = to_num(ch);
		}

		int sum = 0;

		if(a != 1){
			sum += a;
		}else{
			sum += 11;
			ele_used = true;
		}

		if(b != 1 || ele_used){
			sum += b;
		}else{
			sum += 11;
			ele_used = true;
		}

		if(sum == 21){
			cout << "blackjack" << endl;
			continue;
		}else if(sum > 17 || (sum == 17 && !ele_used)){
			cout << sum << endl;
			continue;
		}

		for(int j = 0; j < 8; j++){

			if(card[j] != 1){
				sum += card[j];
			}else if(sum + 11 > 21){
				sum += 1;
			}else{
				sum += 11;
				ele_used = true;
			}

			if(sum > 21){
				if(ele_used){
					sum -= 10;
					ele_used = false;
				}else{
					cout << "bust" << endl;
					break;
				}
			}

			if(sum > 17 || (sum == 17 && !ele_used)){
				cout << sum << endl;
				break;
			}
		}
	}
	return 0;
}