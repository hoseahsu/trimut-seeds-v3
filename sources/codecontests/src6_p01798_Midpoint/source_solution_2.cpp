#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1);

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

struct Point {
	int x, y;
	Point()
	: x(0), y(0) {}
	Point(int _x, int _y)
	: x(_x), y(_y) {}
};
bool IsPara(Point a, Point b) {
	return a.x * b.y == a.y * b.x;
}
Point operator+(Point a, Point b){
	return Point(a.x + b.x, a.y + b.y);
}
Point operator-(Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}
Point operator*(Point a, int b) {
	return Point(a.x * b, a.y * b);
}
Point operator/(Point a, int b) {
	return Point(a.x / b, a.y / b);
}
int operator/(Point a, Point b) {
	if (!IsPara(a, b)) return -1;
	return b.x ? a.x / b.x : b.y ? a.y / b.y : 0;
}
bool operator<(Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator==(Point a, Point b) {
	return a.x == b.x && a.y == b.y;
}
Point crossPoint(Point a, Point va, Point b, Point vb) {
	Point p = b - a;
	int det = va.x * vb.y - vb.x * va.y;
	if (det == 0)
		return Point(-1, -1);
	if ((-p.x * vb.y + p.y * vb.x) % det)
		return Point(-1, -1);
	if ((p.y * va.x - p.x * va.y) % det)
		return Point(-1, -1);
	return a - (va * ((-p.x * vb.y + p.y * vb.x) / det));
}


typedef complex<double> Comp;

bool is_pow_of2(int n) {
	int a = 1;
	while (n >= a) {
		if (n == a) {
			return true;
		}
		a <<= 1;
	}
	return false;
}


void fft(vector<Comp>& v) {
	int n = v.size();
	assert(is_pow_of2(n));

	for (int j = 1, i = 0; j < n - 1; j++) {
		for (int k = n >> 1; k >(i ^= k); k >>= 1);
		if (j < i) swap(v[i], v[j]);
	}

	for (int m = 2; m <= n; m <<= 1) {
		double deg = (-1) * 2 * PI / m;
		Comp r(cos(deg), sin(deg));
		for (int i = 0; i < n; i += m) {
			Comp w(1, 0);
			for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
				Comp t1 = v[j], t2 = w*v[k];
				v[j] = t1 + t2, v[k] = t1 - t2;
				w *= r;
			}
		}
	}
}

void ifft(vector<Comp>& v) {
	int n = v.size();
	assert(is_pow_of2(n));
	for (int j = 1, i = 0; j < n - 1; j++) {
		for (int k = n >> 1; k >(i ^= k); k >>= 1);
		if (j < i) swap(v[i], v[j]);
	}
	for (int m = 2; m <= n; m <<= 1) {
		double deg = 2 * PI / m;
		Comp r(cos(deg), sin(deg));
		for (int i = 0; i < n; i += m) {
			Comp w(1, 0);
			for (int j = i, k = i + m / 2; k < i + m; j++, k++) {
				Comp t1 = v[j], t2 = w*v[k];
				v[j] = t1 + t2, v[k] = t1 - t2;
				w *= r;
			}
		}
	}
	for (int i = 0; i < n; ++i) v[i] *= 1.0 / n;
}

vector<Comp> convolution(vector<Comp> P, vector<Comp> Q) {
	fft(P); fft(Q);
	for (size_t i = 0; i < P.size(); i++) P[i] *= Q[i];
	ifft(P);
	return P;
}

int main()
{
	int L, M, N;
	cin >> L >> M >> N;
	vector<Point> A(L), B(M), C(N);
	for (int i = 0; i < L; i++) {
		cin >> A[i].x >> A[i].y;
		A[i].x += 100000;
		A[i].y += 100000;
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i].x >> B[i].y;
		B[i].x += 100000;
		B[i].y += 100000;
	}
	for (int i = 0; i < N; i++) {
		cin >> C[i].x >> C[i].y;
		C[i].x += 100000;
		C[i].y += 100000;
		C[i] = C[i] * 2;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	Point vA = A.back() - A.front(), vB = B.back() - B.front(), vC = C.back() - C.front();
	int gcdA = gcd(abs(vA.x), abs(vA.y)), gcdB = gcd(abs(vB.x), abs(vB.y)), gcdC = gcd(abs(vC.x), abs(vC.y));
	if (gcdA) vA = vA / gcdA;
	if (gcdB) vB = vB / gcdB;
	if (gcdC) vC = vC / gcdC;
	if (gcdA == 0 && gcdC == 0) {
		auto erb = equal_range(B.begin(), B.end(), C.front() - A.front());
		cout << (ll)(erb.second - erb.first) * C.size() * A.size() << endl;
	}
	else if (gcdB == 0 && gcdC == 0) {
		auto era = equal_range(A.begin(), A.end(), C.front() - B.front());
		cout << (ll)(era.second - era.first) * C.size() * B.size() << endl;
	}
	else if (gcdC == 0) {
		ll res = 0;
		for (int i = 0; i < M; i++) {
			auto erb = equal_range(B.begin(), B.end(), C.front() - A[i]);
			res += C.size() * (erb.second - erb.first);
		}
		cout << res << endl;
	}
	else if (IsPara(vA, vB) && IsPara(vC, A.front() + B.front() - C.front())) {
		Point sA = A.front(), sB = B.front();
		vector<Comp> lA(1 << 20), lB(1 << 20);
		map<int, ll> lC;
		if (gcdA) {
			if (vA.y >= 0) {
				int maxi = max(min(vA.x ? sA.x / vA.x : 1000000, vA.y ? sA.y / vA.y : 1000000) + 1, 0);
				sA = sA - (vA * maxi);
			}
			else {
				sA = sA - (vA * (max(min(vA.x ? sA.x / vA.x : 1000000, (sA.y - 200000) / vA.y) + 1, 0)));
			}
		}
		if (gcdB) {
			if (vB.y >= 0) {
				int maxi = max(min(vB.x ? sB.x / vB.x : 1000000, vB.y ? sB.y / vB.y : 1000000) + 1, 0);
				sB = sB - (vB * maxi);
			}
			else {
				sB = sB - (vB * (max(min(vB.x ? sB.x / vB.x : 1000000, (sB.y - 200000) / vB.y) + 1, 0)));
			}
		}
		Point sC = sA + sB;
		for (int i = 0; i < L; i++) {
			lA[(A[i] - sA) / vA] += 1;
		}
		for (int i = 0; i < M; i++) {
			lB[(B[i] - sB) / vB] += 1;
		}
		auto conv = convolution(lA, lB);
		for (int i = 0; i < N; i++) {
			lC[(C[i] - C.front()) / vC]++;
		}
		ll res = 0;
		for (int i = 0; i < (1 << 19); i++) {
			if (IsPara(vC, sC + (vA * i) - C.front())) {
				res += lC[(sC + (vA * i) - C.front()) / vC] * (ll)round(conv[i].real());
			}
		}
		cout << res << endl;
	}
	else {
		ll res = 0;
		if (IsPara(vA, vC)) {
			for (int i = 0; i < M; i++) {
				Point cp = crossPoint(A[i] + B.front(), vB, C.front(), vC);
				if (cp.x < 0) continue;
				auto erc = equal_range(C.begin(), C.end(), cp);
				auto erb = equal_range(B.begin(), B.end(), cp - A[i]);
				res += (erc.second - erc.first) * (erb.second - erb.first);
			}
		}
		else {
			for (int i = 0; i < L; i++) {
				Point cp = crossPoint(B[i] + A.front(), vA, C.front(), vC);
				if (cp.x < 0) continue;
				auto erc = equal_range(C.begin(), C.end(), cp);
				auto era = equal_range(A.begin(), A.end(), cp - B[i]);
				res += (erc.second - erc.first) * (era.second - era.first);
			}
		}
		cout << res << endl;
	}
	return 0;
}