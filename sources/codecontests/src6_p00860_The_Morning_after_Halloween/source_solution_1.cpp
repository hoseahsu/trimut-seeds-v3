#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int w, h, n;
string b[16];
int sx[3], sy[3], gx[3], gy[3];
short v[1 << 24];
short dist[3][16][16];

int dx[5] = { 0, 1, 0, -1, 0 }, dy[5] = { 0, 0, 1, 0, -1 };

struct S {
	unsigned char x[3], y[3];
	float h;
	bool operator < (const S& s) const { return h > s.h; }
};

float calcH(S& s) {
	float ret = 0;
	for(int i = 0; i < n; i++) {
		ret = max(ret, (float)dist[i][s.y[i]][s.x[i]]);
	}
	return 1.1 * ret;
}


int conv(S s) {
	int ret = 0;
	for(int i = 0; i < n; i++) {
		ret = ret * 16 + s.x[i];
	}
	for(int i = 0; i < n; i++) {
		ret = ret * 16 + s.y[i];
	}
	return ret;
}

bool check(S s) {
	for(int i = 0; i < n; i++) {
		if(s.x[i] != gx[i] || s.y[i] != gy[i]) return false;
	}
	return true;
}

bool in(int x, int y) {
	return 0 <= x && x < w && 0 <= y && y < h;
}

bool valid(S s, S ps) {
	for(int i = 0; i < n; i++) {
		if(!in(s.x[i], s.y[i])) return false;
		if(b[s.y[i]][s.x[i]] == '#') return false;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(s.x[i] == s.x[j] && s.y[i] == s.y[j]) return false;
			if(ps.x[j] == s.x[i] && ps.y[j] == s.y[i] &&
				ps.x[i] == s.x[j] && ps.y[i] == s.y[j]) return false;
		}
	}
	return true;
}

void view(S s) {
	string temp[16];
	for(int i = 0; i < h; i++) {
		temp[i] = b[i];
	}
	for(int i = 0; i < n; i++) {
		temp[s.y[i]][s.x[i]] = 'a' + i;
	}
	for(int i = 0; i < h; i++) {
		cout << temp[i] << endl;
	}
	cout << endl;
}

void makeNS(int i, S s, S& ps, vector<S>& res) {
	if(i == n) {
		if(valid(s, ps)) res.push_back(s);
		return;
	}
	for(int k = 0; k < 5; k++) {
		S ns = s;
		ns.x[i] += dx[k];
		ns.y[i] += dy[k];
		makeNS(i + 1, ns, ps, res);
	}
}

int main() {
	while(cin >> w >> h >> n, w | h | n) {
		cin.ignore();
		S s;
		for(int i = 0; i < h; i++) {
			getline(cin, b[i]);
			for(int j = 0; j < w; j++) {
				if(b[i][j] == 'a') s.x[0] = j, s.y[0] = i;
				if(b[i][j] == 'b') s.x[1] = j, s.y[1] = i;
				if(b[i][j] == 'c') s.x[2] = j, s.y[2] = i;
				if(b[i][j] == 'A') gx[0] = j, gy[0] = i;
				if(b[i][j] == 'B') gx[1] = j, gy[1] = i;
				if(b[i][j] == 'C') gx[2] = j, gy[2] = i;
				if(b[i][j] == 'a' || b[i][j] == 'b' || b[i][j] == 'c') b[i][j] = ' ';
			}
			//cout << b[i] << endl;
		}

		memset(dist, -1, sizeof dist);
		for(int l = 0; l < n; l++) {
			for(int i = 0; i < h; i++) {
				for(int j = 0; j < w; j++) {
					if(b[i][j] == '#') continue;
					queue<pair<int, int>> q;
					q.push(make_pair(gx[l], gy[l]));
					dist[l][gy[l]][gx[l]] = 0;
					while(q.size()) {
						int x = q.front().first, y = q.front().second;
						q.pop();
						for(int k = 1; k < 5; k++) {
							int nx = x + dx[k], ny = y + dy[k];
							if(b[ny][nx] == '#') continue;
							if(dist[l][ny][nx] != -1) continue;
							dist[l][ny][nx] = dist[l][y][x] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}


		memset(v, -1, sizeof v);

		priority_queue<S> q;
		s.h = calcH(s);
		q.push(s);
		v[conv(s)] = 0;
		int ans = -1;
		while(q.size()) {
			s = q.top();
			q.pop();
			int d = v[conv(s)];

			//cout << conv(s)  << " " << d << endl;
			//view(s);
			if(check(s)) {
				ans = d;
				break;
			}

			vector<S> NS;
			makeNS(0, s, s, NS);
			for(S ns : NS) {
				int X = conv(ns);
				if(v[X] != -1 && v[X] <= d + 1) continue;
				v[X] = d + 1;
				ns.h = calcH(ns) + d + 1;
				q.push(ns);
			}
		}

		cout << ans << endl;
		//return 0;
	}

}