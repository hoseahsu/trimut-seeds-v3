#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count etc.
#include <cstdlib>	// require abs
#include <cstdio>	// require printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>	// require tolower, toupper
#include <fstream>	// require freopen
#include <stdint.h>	// require uint64_t

using namespace std;

int main()
{
	int price[][7] = { 
			{   0, 300, 500, 600, 700,1350,1650 },
			{   0,   0, 350, 450, 600,1150,1500 },
			{   0,   0,   0, 250, 400,1000,1350 },
			{   0,   0,   0,   0, 250, 850,1300 },
			{   0,   0,   0,   0,   0, 600,1150 },
			{   0,   0,   0,   0,   0,   0, 500 },
			{   0,   0,   0,   0,   0,   0,   0 } };
	int dist[][7] = {
			{   0,   0,   0,   0,   0,   0,   0 },
			{   6,   0,   0,   0,   0,   0,   0 },
			{  13,   7,   0,   0,   0,   0,   0 },
			{  18,  12,   5,   0,   0,   0,   0 },
			{  23,  17,  10,   5,   0,   0,   0 },
			{  43,  37,  30,  25,  20,   0,   0 },
			{  58,  52,  45,  40,  35,  15,   0 } };

	for (int i = 0; i < 7; ++i ){
		for (int j = 0; j < 7; ++j ){
			if (i != j ){
				if (price[i][j] == 0 ){
						price[i][j] = price[j][i];
				} // end if
				if (dist[i][j] == 0 ){
					dist[i][j] = dist[j][i];
				} // end if
			} // end if
		} // en for
	} // end for  
			 
		
//	cut here before submit 
//	freopen ("testcase.highwaytoll", "r", stdin );
	int from;

	while (cin >> from && from ){
		int fromh, fromm;
		cin >> fromh >> fromm;
		int to,toh, tom;
		cin >> to >> toh >> tom;
		from--;to--;
		int res = 0;
		int em = fromh*60 + fromm;
		int dm = toh*60 + tom;

		// ツ環暗クツ妥篠湘崢づ個篠楪甘板妥堕づづ債づ按つ「
//		if (em < 17*60 + 30 && dm > 19*60 + 30 ){
		if ( (17*60 + 30 <= em && em <= 19*60 + 30 ) 
		||   (17*60 + 30 <= dm && dm <= 19*60 + 30 ) ){ 
			int d = dist[from][to];
			if (d > 40 ){
				res = price[from][to];
			}else{
				res = (price[from][to]/2 + 49)/50*50;
			} // end if
 		}else{
				res = price[from][to];
		} // end if
		cout << res << endl;	

	} // end loop

		
	return 0;
}