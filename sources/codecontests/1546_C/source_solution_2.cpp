#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>

void solve() {
	int n;
	std::cin >> n;
	std::vector <int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}
	std::vector <int> sorted_num = numbers;
	std::sort(sorted_num.begin(), sorted_num.end());
	
	std::map <int, int> odd, even;
	for (int i = 0; i < n; ++i) {
		if (i%2==0)
			even[sorted_num[i]]++;
		else 
			odd[sorted_num[i]]++;
	}
	bool possible = true;

	for (int i = 0; i < n; ++i) {
		if (i%2==0) {
			if (even[numbers[i]] == 0) {
				possible = false;
				break;
			}
			else {
				even[numbers[i]]--;
			}
		}
		else {
			if (odd[numbers[i]] == 0) {
				possible = false;
				break;
			}
			else {
				odd[numbers[i]]--;
			}
		}
	}
	if (possible)
		std::cout << "YES" << std::endl;
	else 
		std::cout << "NO" << std::endl;
}

int main () {
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
