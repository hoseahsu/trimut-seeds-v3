#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) (v).begin(), (v).end()
#define rev(s) (s).rbegin(), (s).rend()
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;

void checkace(int &hand, int &ace){
	if(ace && hand > 21){
		hand -= 10;
		ace--;
	}
}

int main(){
	int dataset;
	cin >> dataset;
	map<char, int> card;
	rep(i, 9){
		card['1'+i] = 1+i;
	}
	rep(i, 4){
		card["TJQK"[i]] = 10;
	}
	card['A'] = 11;
	while(dataset--){
		int hand = 0, ace = 0;
		rep(i, 2){
			char c;
			cin >> c;
			int n = card[c];
			hand += n;
			if(n == 11) ace++;
		}
		checkace(hand, ace);

		queue<int> pile;
		rep(i, 8){
			char c;
			cin >> c;
			pile.push(card[c]);
		}
		bool bj = hand==21;
		while(hand <= 16 || (hand == 17 && ace > 0)){
			int n = pile.front();
			pile.pop();
			hand += n;
			if(n == 11) ace++;
			checkace(hand, ace);
		}

		if(hand > 21) cout << "bust" << endl;
		else{
			if(bj){
				cout << "blackjack" << endl;
			}else{
				cout << hand << endl;
			}
		}
	}

	return 0;
}