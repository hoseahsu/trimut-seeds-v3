/*
Author : notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <cctype>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

vector<int> merge(int lines, vector<int> &arr1, vector<int> &arr2)
{
  vector<int> result;
  while (arr1.size() && arr2.size())
  {
    if (arr1.front() <= lines)
    {
      if (arr1.front() == 0)
        ++lines;
      result.push_back(arr1.front());
      arr1.erase(arr1.begin());
    }
    else if (arr2.front() <= lines)
    {
      if (arr2.front() == 0)
        ++lines;
      result.push_back(arr2.front());
      arr2.erase(arr2.begin());
    }
    else
      return {-1};
  }

  if (arr2.size())
    arr1 = arr2;

  while (arr1.size())
  {
    if (arr1.front() <= lines)
    {
      result.push_back(arr1.front());
      if (arr1.front() == 0)
        ++lines;
    }
    else
      return {-1};
    arr1.erase(arr1.begin());
  }

  return result;
}

void solve()
{
  int lines, n, m;
  cin >> lines >> n >> m;
  vector<int> arr1(n), arr2(m);
  for (int &x : arr1)
  {
    cin >> x;
  }
  for (int &x : arr2)
  {
    cin >> x;
  }

  vector<int> result = merge(lines, arr1, arr2);
  for (auto x : result)
  {
    cout << x << " ";
  }
  cout << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  string temp;
  getline(cin, temp);
  getline(cin, temp);
  while (t--)
  {
    solve();
    getline(cin, temp);
    getline(cin, temp);
  }

  return 0;
}
