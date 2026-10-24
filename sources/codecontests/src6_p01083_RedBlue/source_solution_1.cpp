#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>

constexpr double EPS = 0.000000001;
struct Coordinate;
struct Vector;
struct Segment;
struct Angle;
struct Line;
struct Circle;
struct Coordinate {
	double x, y;
	double distance(const Coordinate& that) const;
	Vector operator-(const Coordinate& from) const;
};
struct Vector {
	double x, y;
	Vector rotate(const Angle& angle) const;
	double dot(const Vector& that) const;
	double cross(const Vector& that) const;
	double length() const;
};
Vector operator*(const double& scala, const Vector& vec);
Vector operator*(const Vector& vec, const double scala);
Coordinate operator+(const Coordinate& coord, const Vector& diff);
Coordinate operator+(const Vector& diff, const Coordinate& coord);
struct Segment {
	Coordinate end_a, end_b;
	bool has_intersection(const Circle& that) const;
	double distance(const Coordinate& that) const;
};
struct Angle {
	double sin, cos;
	static Angle from_sin(const double sin);
	Angle operator+(const Angle& that) const;
	Angle operator-() const;
};
struct Line {
private:
	const Coordinate from, to;
	Vector vec() const { return to - from; }
	double a() const { return to.y - from.y; }
	double b() const { return from.x - to.x; }
	double c() const { return - a() * from.x - from.y * b(); }
public:
	Line(const Coordinate& a, const Coordinate& b) : to{ a }, from{ b } {};
	bool is_cross(const Line& that) const;
	Coordinate cross_point(const Line& that) const;
};
struct Circle {
	Coordinate center;
	double radius;
	std::vector<Line> tangents(const Coordinate& that) const;
};

double Coordinate::distance(const Coordinate& that) const
{
	return (*this - that).length();
}

Vector Coordinate::operator-(const Coordinate& from) const
{
	return Vector{ x - from.x, y - from.y };
}

Vector Vector::rotate(const Angle& angle) const
{
	auto len = length();
	auto a = Angle{ y / len, x / len } + angle;
	return Vector{ a.cos * len, a.sin* len };
}

double Vector::dot(const Vector& that) const
{
	return x * that.x + y * that.y;
}

double Vector::cross(const Vector& that) const
{
	return x * that.y - y * that.x;
}

double Vector::length() const
{
	return std::sqrt(x * x + y * y);
}

Vector operator*(const double& scala, const Vector& vec)
{
	return Vector{ vec.x * scala, vec.y * scala };
}

Vector operator*(const Vector& vec, const double scala)
{
	return Vector{ vec.x * scala, vec.y * scala };
}

Coordinate operator+(const Coordinate& coord, const Vector& diff)
{
	return Coordinate{ coord.x + diff.x, coord.y + diff.y };
}

Coordinate operator+(const Vector& diff, const Coordinate& coord)
{
	return Coordinate{ diff.x + coord.x, diff.y + coord.y };
}

std::vector<Line> Circle::tangents(const Coordinate& that) const
{
	const auto mid = center - that;
	const auto angle = Angle::from_sin(radius / center.distance(that));
	return { Line(that, mid.rotate(angle) + that), Line(that, mid.rotate(-angle) + that) };
}

bool Line::is_cross(const Line& that) const
{
	return std::abs(vec().cross(that.vec())) > 0;
}

Coordinate Line::cross_point(const Line& that) const
{
	const auto d = a() * that.b() - that.a() * b();
	return Coordinate{ (b() * that.c() - that.b() * c()) / d, (that.a() * c() - a() * that.c()) / d };
}

Angle Angle::from_sin(const double sin)
{
	return Angle{ sin, std::sqrt(1 - sin * sin) };
}

Angle Angle::operator+(const Angle& that) const
{
	return Angle{ sin * that.cos + cos * that.sin, cos * that.cos - sin * that.sin };
}

Angle Angle::operator-() const
{
	return Angle{ -sin, cos };
}

bool Segment::has_intersection(const Circle& that) const
{
	return distance(that.center) < that.radius - EPS;
}

double Segment::distance(const Coordinate& that) const
{
	const auto vec = end_a - end_b;
	if (vec.dot(that - end_b) >= 0 && vec.dot(end_a - that) >= 0) {
		return std::abs(vec.y * that.x - vec.x * that.y + end_a.x * end_b.y - end_a.y * end_b.x) / std::sqrt(vec.y * vec.y + vec.x * vec.x);
	}
	else {
		return std::min(end_a.distance(that), end_b.distance(that));
	}
}

struct Edge {
	int to;
	double cost;
	Edge* pair{ nullptr };
	bool has_flow;
	Edge(int _to, double _cost, bool _has_flow) :to{ _to }, cost{ _cost }, has_flow{ _has_flow }{};
};
template<typename K, typename V>
struct KeyWithValue {
	K key;
	V value;
	KeyWithValue(const K& k, const V& v) :key{ k }, value{ v }{};
};
template<typename K, typename V>
bool operator>(const KeyWithValue<K, V>& a, const KeyWithValue<K, V>& b) {
	return a.key > b.key;
}
void set_edge(std::vector<std::vector<Edge>>& node, const int from, const int to, double cost) {
	node[from].emplace_back(to, cost, true);
	node[to].emplace_back(from, -cost, false);
	node[from].back().pair = &node[to].back();
	node[to].back().pair = &node[from].back();
}
double min_cost_matching(std::vector<std::vector<Edge>> &nodes, const int flow, const int source, const int sink) {
	std::vector<double> min_cost(nodes.size());
	std::vector<double> potential(nodes.size(), 0);
	std::vector<Edge*> prev(nodes.size(), nullptr);
	std::priority_queue<KeyWithValue<double, int>, std::vector<KeyWithValue<double, int>>, std::greater<KeyWithValue<double, int>>> queue;
	double result = 0;
	for (auto _i = 0; _i < flow; ++_i) {
		std::fill(min_cost.begin(), min_cost.end(), DBL_MAX);
		min_cost[source] = 0;
		queue.emplace(0.0, source);
		while (!queue.empty()) {
			auto top = queue.top(); queue.pop();
			if (top.key == min_cost[top.value]) {
				for (auto& edge : nodes[top.value]) if (edge.has_flow) {
					if (min_cost[edge.to] > potential[top.value] + edge.cost - potential[edge.to] + top.key + EPS) {
						min_cost[edge.to] = potential[top.value] + edge.cost - potential[edge.to] + top.key;
						prev[edge.to] = &edge;
						queue.emplace(min_cost[edge.to], edge.to);
					}
				}
			}
		}
		if (min_cost[sink] == DBL_MAX) return -1;
		for (auto i = 0; i < nodes.size(); ++i) potential[i] += min_cost[i];
		result += potential[sink];
		auto last = sink;
		while (last != source) {
			auto prev_edge = prev[last];
			prev_edge->has_flow = false;
			prev_edge->pair->has_flow = true;
			last = prev_edge->pair->to;
		}
	}
	return result;
}
double cal_min_cost(const std::vector<Coordinate>& red, const std::vector<Coordinate>& blue, const std::vector<Circle>& circles) {
	std::vector<std::vector<std::vector<Line>>> red_tangents(red.size()), blue_tangents(blue.size());
	for (auto i = 0; i < red.size(); ++i) {
		for (const auto &circle: circles) {
			red_tangents[i].push_back(circle.tangents(red[i]));
			blue_tangents[i].push_back(circle.tangents(blue[i]));
		}
	}
	const int source = red.size() + blue.size();
	const int sink = source + 1;
	std::vector<std::vector<Edge>> node(sink + 1); for (auto& n : node) n.reserve(red.size() + 1);
	for (auto r = 0; r < red.size(); ++r) for (auto b = 0; b < blue.size(); ++b){
		const auto red_pos = red[r];
		const auto blue_pos = blue[b];
		double min_cost = DBL_MAX;
		const auto direct = Segment{ red_pos, blue_pos };
		bool is_blocked = false;
		for (const auto& c : circles) if (!is_blocked) {
			is_blocked = direct.has_intersection(c);
		}
		if (is_blocked) {
			for (auto i = 0; i < circles.size(); ++i) for (auto j = 0; j < circles.size(); ++j) {
				for (const auto& red_tangent : red_tangents[r][i]) for (const auto& blue_tangent : blue_tangents[b][j]) if (red_tangent.is_cross(blue_tangent)) {
					const auto cross_point = red_tangent.cross_point(blue_tangent);
					const auto red_to_cp = Segment{ cross_point, red_pos };
					const auto blue_to_cp = Segment{ cross_point, blue_pos };
					bool is_blocked = false;
					for (auto c = 0; c < circles.size() && !is_blocked; ++c) {
						/*
						if (i == c && red_to_cp.has_intersection(circles[c])) {
							std::cerr << "i: " << i << '\n';
						}
						if (j == c && blue_to_cp.has_intersection(circles[c])) {
							std::cerr << "i: " << i << '\n';
						}
						*/
						is_blocked = ((i != c) && red_to_cp.has_intersection(circles[c])) || ((j != c) && blue_to_cp.has_intersection(circles[c]));
					}
					if (!is_blocked) {
						min_cost = std::min(min_cost, red_pos.distance(cross_point) + blue_pos.distance(cross_point));
					}
				}
			}
		}
		else {
			min_cost = red_pos.distance(blue_pos);
		}
		if (min_cost <= 10000) {
			set_edge(node, r, b + red.size(), min_cost);
		}
	}
	for (auto r = 0; r < red.size(); ++r) {
		set_edge(node, source, r, 0);
	}
	for (auto b = 0; b < blue.size(); ++b) {
		set_edge(node, b + red.size(), sink, 0);
	}
	return min_cost_matching(node, red.size(), source, sink);
}
int main() {
	int n; std::cin >> n;
	std::vector<Circle> circles(2); for (auto& c : circles) std::cin >> c.center.x >> c.center.y >> c.radius;
	std::vector<Coordinate> red(n), blue(n); 
	for (auto& r : red) std::cin >> r.x >> r.y;
	for (auto& b : blue) std::cin >> b.x >> b.y;
	auto min_cost = cal_min_cost(red, blue, circles);
	if (min_cost >= 0) {
		std::cout << std::setprecision(10) << std::fixed << min_cost << '\n';
	}
	else {
		std::cout << "Impossible\n";
	}
	return 0;
}
