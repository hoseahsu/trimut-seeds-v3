//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int solve(int m, int c, int n)
{
	queue<int>* queries = new queue<int>[n];
	int cost = 0;
	int k;
	for(int i = 0; i < n; i++)
	{
		cin >> k;
		for(int j = 0;j < k; j++)
		{
			int book_id;
			cin >> book_id;
			queries[i].push(book_id);
		}
	}

	deque<int>* desks = new deque<int>[m];
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i = 0; i < n; i++)
		{
			if(queries[i].empty())
				continue;
			flag = true;
			int book = queries[i].front(); queries[i].pop();
			// find book
			int pos = m;
			for(int j = 0; j < m; j++)
			{
				if(count(desks[j].begin(), desks[j].end(), book) > 0){
					pos = j;
					break;
				}
			}
			if(pos < m)
				desks[pos].erase(find(desks[pos].begin(), desks[pos].end(), book));

			cost += pos + 1;

			if((int)desks[0].size() < c)
			{
				desks[0].push_back(book);
				cost += 1;
			}else{
				// step 1 : move from shelf(current position) to non-full nearest to entrance desk
				int pos_2 = m;
				for(int j = 0; j < m; j++)
				{
					if((int)desks[j].size() < c)
					{
						pos_2 = j;
						break;
					}
				}
				if(pos_2 < m)
					desks[pos_2].push_front(book);
				cost += pos_2 + 1;

				// step 2 : move least recently used from desk 1
				int pos_3 = m;
				for(int j = 0; j < m; j++)
				{
					if((int)desks[j].size() < c)
					{
						pos_3 = j;
						break;
					}
				}
				int lru = desks[0].front(); desks[0].pop_front();
				if(pos_3 < m)
					desks[pos_3].push_back(lru);

				cost += 1 + pos_3;
				cost += 1;

				// step 3 : move book from pos_2 to desk 1
				if(pos_2 < m)
					desks[pos_2].pop_front();
				desks[0].push_back(book);
				cost += pos_2 + 1;
				cost += 1;
			}
		}
	}

	deque<int> dq;
	for(int i = 0; i < m; i++)
	{
		swap(desks[i], dq);
	}

	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		swap(queries[i], q);
	}

	delete[] desks;
	delete[] queries;
	return cost;
}

int main() {
	int m, c, n;
	cin >> m >> c >> n;
	while(m != 0 && c != 0 && n != 0)
	{
		cout << solve(m,c,n) << endl;
		cin >> m >> c >> n;
	}
	return 0;
}