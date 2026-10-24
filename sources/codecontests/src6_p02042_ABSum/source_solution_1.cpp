#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>
#include <set>

int main(void) {
	int n, m; std::cin >> n >> m;
	std::vector<int> numbers(n); for (auto& a : numbers) std::cin >> a;
	std::priority_queue<int> greater, less;
	for (auto i = 0; i < n; ++i) {
		if (i > numbers[i]) {
			greater.push(-i);
			less.push(numbers[i]);
		}
		else {
			greater.push(-numbers[i]);
			less.push(i);
		}
	}
	for (auto i = 0; i < m; ++i) {
		if (less.top() + greater.top() > 0) {
			const auto l = less.top(); less.pop();
			const auto g = greater.top(); greater.pop();
			less.push(-g);
			greater.push(-l);
		}
		else break;
	}
	long long int result = 0;
	for (auto i = 0; i < n; ++i) {
		result += -less.top() + -greater.top();
		less.pop(); greater.pop();
	}
	std::cout << result << std::endl;
}

