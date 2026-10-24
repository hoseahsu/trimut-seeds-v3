#include <iostream>
#include <string>
using namespace std;

int h, w;
string s[50];

int main() {
	int i, j, di, dj;
	
	cin >> h >> w;
	for (i = 0; i < h; i++) cin >> s[i];
	
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (s[i][j] == '#') { cout << '#'; continue; }
			
			int cnt = 0;
			for (di = -1; di <= 1; di++) {
				for (dj = -1; dj <= 1; dj++) {
					if (0 <= i + di && i + di < h && 0 <= j + dj && j + dj < w && s[i + di][j + dj] == '#') {
						cnt++;
					}
				}
			}
			cout << cnt;
		}
		cout << endl;
	}
	return 0;
}