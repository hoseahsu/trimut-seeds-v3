#include<bits/stdc++.h>
/*
*/

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int>D( N );
	for( size_t i = 0; i < N; i++ ) {
		cin >> D[i];
	}
	double maxans = 1, minans = 0;
	for( size_t idx = 0; idx < 40; idx++ ) {
		double midans = ( maxans + minans ) / 2;
		set<int>prev;
		prev.insert( 1 );
		for( size_t i = 0; i < N; i++ ) {
			double minvalue = D[i] * ( 1. - midans );
			double maxvalue = D[i] * ( 1. + midans );
			set<int>next;
			for( auto one : prev ) {
				for( int j = minvalue / one + 1; j <= maxvalue / one; j++ ) {
					next.insert( j*one );
				}
			}
			prev = next;
		}
		if( prev.size() ) {
			maxans = midans;
		} else {
			minans = midans;
		}

	}
	cout << fixed << setprecision( 20 ) << minans << endl;
}