#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
class Point;
class Sentinel;
class Point {
	long double x, y;
public:
	Point(const double &a = { 0 }, const double &b = { 0 }) :x(a), y(b) {};
	bool operator<(const Point &other) const {
		return (x < other.x) || ((x == other.x) && (y < other.y));
	}
	bool operator>(const Point &other) const {
		return other < *this;
	}
	long double operator*(const Point &other) const {
		return x * other.y - y * other.x;
	}
	void inspect() const {
		std::cout << x << "-" << y << std::endl;
	}
	Point operator-(const Point &other) const {
		return Point(x - other.x, y - other.y);
	}
};
class Sentinel : public Point {
public:
	Sentinel() :Point(10000,10000) {};
};
std::list<Point> sort(std::vector<Point> &vec, const int &left, const int &right) {
	if (left == right) {
		return std::list<Point>{vec.at(left), Sentinel()};
	}
	else {
		std::list<Point> l = sort(vec, left, left + (right - left) / 2);
		std::list<Point> r = sort(vec, left + 1 + (right - left) / 2, right);
		std::list<Point> res;
		for (const auto &a : l) {
			while (r.front() < a) {
				res.push_back(r.front());
				r.pop_front();
			}
			res.push_back(a);
		}
		return res;
	}
}
double sub(const Point &a, const Point &b, const Point &c) {
	return (a - b) * (b - c);
}
int main() {
	int n;
	std::cin >> n;
	while (n != 0) {
		std::vector<Point> vec(n);
		for (auto &v : vec) {
			double x, y;
			std::scanf("%lf,%lf", &x, &y);
			v = Point(x, y);
		}
		auto list = sort(vec, 0, n - 1);
		list.pop_back();
		std::vector<Point> a(n + 2), b(n + 2);
		a.at(0) = list.front(), a.at(1) = list.front(), b.at(0) = list.front(), b.at(1) = list.front();
		auto i = 1, j = 1;
		for (const auto &p : list) {
			while (sub(a.at(i - 1), a.at(i), p) > 0) {
				--i;
				//std::cout << i << "-";
			}
			a.at(++i) = p;
			//std::cout << i << std::endl;
			while (sub(b.at(j - 1), b.at(j), p) < 0) {
				--j;
				//std::cout << j << "=";
			}
			b.at(++j) = p;
			//std::cout << j <<  std::endl;
		}
		std::cout << n - i - j + 4 << std::endl;
		std::cin >> n;
	}
	return 0;
}