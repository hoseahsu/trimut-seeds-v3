#include <bits/stdc++.h>
const int MAX_N = 200000;
char getch(FILE *fin) {
  char ch = fgetc(fin);
  while (ch == ' ' || ch == '\n') ch = fgetc(fin);
  return ch;
}
int getnr(FILE *fin) {
  int nr = 0;
  char ch = getch(fin);
  while (isdigit(ch)) {
    nr = nr * 10 + ch - '0';
    ch = fgetc(fin);
  }
  return nr;
}
std::pair<long long, char> get_cluster(FILE *fin) {
  int len = getnr(fin);
  char ch = getch(fin);
  while (!isalpha(ch)) ch = getch(fin);
  return std::make_pair(len, ch);
}
std::vector<std::pair<long long, char>> str1, str2;
void push_cluster(std::pair<long long, char> cluster,
                  std::vector<std::pair<long long, char>> &str) {
  if (str.empty() || (!str.empty() && str.back().second != cluster.second))
    str.push_back(cluster);
  else
    str[str.size() - 1].first += cluster.first;
}
int kmp[MAX_N + 1 + MAX_N];
std::vector<int> pattern_matching(
    const std::vector<std::pair<long long, char>> &pattern,
    const std::vector<std::pair<long long, char>> &query) {
  std::vector<std::pair<long long, char>> huge_string;
  for (int i = 1; i + 1 < pattern.size(); ++i)
    huge_string.push_back(pattern[i]);
  huge_string.push_back({-1, -1});
  for (int i = 0; i < query.size(); ++i) huge_string.push_back(query[i]);
  std::vector<int> matches;
  for (int i = 1; i < huge_string.size(); ++i) {
    kmp[i] = kmp[i - 1];
    while (kmp[i] != 0 && huge_string[i] != huge_string[kmp[i]])
      kmp[i] = kmp[kmp[i] - 1];
    if (huge_string[i] == huge_string[kmp[i]]) ++kmp[i];
    if (kmp[i] == pattern.size() - 2 && i >= pattern.size() - 2 + 1)
      matches.push_back(i - (pattern.size() - 2 + 1));
  }
  return matches;
}
bool included(std::pair<long long, char> a, std::pair<long long, char> b) {
  return a.second == b.second && (a.first <= b.first);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) push_cluster(get_cluster(stdin), str1);
  for (int i = 0; i < m; ++i) push_cluster(get_cluster(stdin), str2);
  long long res = 0;
  if (str2.size() == 1) {
    for (int i = 0; i < str1.size(); ++i)
      if (included(str2[0], str1[i])) res += str1[i].first - str2[0].first + 1;
  } else {
    std::vector<int> matches = pattern_matching(str2, str1);
    for (auto it : matches)
      if (it + 1 < str1.size() && it - (str2.size() - 2) >= 0 &&
          included(str2.back(), str1[it + 1]) &&
          included(str2.front(), str1[it - (str2.size() - 2)]))
        ++res;
  }
  printf("%lld", res);
  return 0;
}
