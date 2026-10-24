#include <bits/stdc++.h>

int N;
int64_t L;
std::vector<std::pair<int64_t, int64_t>> intervals;

int64_t calcX();
int64_t calcY();

int main()
{
	scanf("%d%lld", &N, &L);
	intervals.resize(N);
	for (auto& e: intervals) scanf("%lld%lld", &e.first, &e.second);
	printf("%d %d\n", calcX(), calcY());

	return 0;
}

int64_t calcX()
{
	std::sort(intervals.begin(), intervals.end());
	std::priority_queue<int64_t> available;
	int64_t right{};
	int ans{}, index{};
	while (right < L)
	{
		while (index < N && intervals[index].first <= right)
		{
			available.push(intervals[index].second);
			index++;
		}
		ans++;
		right = available.top();
		available.pop();
	}
	return ans;
}

int64_t calcY()
{
	std::vector<std::pair<int64_t, int>> points(2 * N);
	for (int i{}; i < N; i++)
	{
		points[i].first = intervals[i].first;
		points[N + i].first = intervals[i].second;
	}
	std::sort(points.begin(), points.end());
	points.erase(std::unique(points.begin(), points.end()), points.end());
	for (auto& e: intervals)
	{
		std::pair<int64_t, int> tmp(e.first, -N);
		std::lower_bound(points.begin(), points.end(), tmp)->second++;
		tmp.first = e.second;
		std::lower_bound(points.begin(), points.end(), tmp)->second--;
	}
	for (int i{1}; i < (int)points.size(); i++)
		points[i].second += points[i - 1].second;
	int min{1 << 30};
	for (int i{}; i < (int)points.size() - 1; i++)
		min = std::min(min, points[i].second);
	return N - min + 1;
}
