// 2014/01/30 Tazoe

#include <iostream>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	int K;
	cin >> K;

	int J[1001][1001];
	int O[1001][1001];
	for(int y=0; y<=M; y++){
		J[y][0] = O[y][0] = 0;
	}
	for(int x=0; x<=N; x++){
		J[0][x] = O[0][x] = 0;
	}

	for(int y=1; y<=M; y++){
		for(int x=1; x<=N; x++){
			char c;
			cin >> c;

			J[y][x] = J[y-1][x]+J[y][x-1]-J[y-1][x-1];
			O[y][x] = O[y-1][x]+O[y][x-1]-O[y-1][x-1];

			if(c=='J'){
				J[y][x]++;
			}
			else if(c=='O'){
				O[y][x]++;
			}
		}
	}

	for(int i=0; i<K; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int cnt_J = J[c][d]-J[a-1][d]-J[c][b-1]+J[a-1][b-1];
		int cnt_O = O[c][d]-O[a-1][d]-O[c][b-1]+O[a-1][b-1];
		int cnt_I = (c-a+1)*(d-b+1)-cnt_J-cnt_O;

		cout << cnt_J << ' ' << cnt_O << ' ' << cnt_I << endl;
	}

	return 0;
}