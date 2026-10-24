#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return (a) ? GCD(b % a, a) : b; }
long long LCM(long long a, long long b) { return a * b / GCD(a, b); }
long long fastpow(long long b, long long p) {
  if (!p) return 1;
  long long ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
string alpha = "abcdefghijklmnopqrstuvwxyz";
int divisor(int number) {
  int i;
  for (i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) {
      return number / i;
    }
  }
  return 1;
}
int myXOR(int x, int y) {
  int res = 0;
  for (int i = 31; i >= 0; i--) {
    bool b1 = x & (1 << i);
    bool b2 = y & (1 << i);
    bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
    res <<= 1;
    res |= xoredBit;
  }
  return res;
}
void printDivisors(int n, vector<int>& v) {
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i && i > 1)
        v.push_back(i);
      else {
        if (i > 1) v.push_back(i);
        if (n / i > 1) v.push_back(n / i);
      }
    }
  }
}
int bin(vector<int> vec, int val) {
  int l = 0, r = vec.size() - 1, mid = r / 2;
  while (l <= r) {
    mid = (l + r) / 2;
    if (vec[mid] < val && vec[mid + 1] > val) {
      if (vec[mid + 1] == val) return mid + 1;
      return mid;
    } else if (vec[mid] > val) {
      r = mid - 1;
    } else if (vec[mid] < val) {
      l = mid + 1;
    } else if (vec[mid] == val)
      return mid;
  }
  return -1;
}
void clear(vector<bool> v) {
  for (int i = 0; i < v.size(); i++) v[i] = 0;
}
bool comp(const string& s1, const string& s2) { return s2 + s1 < s1 + s2; }
vector<string> split(const string& s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}
int countWords(string str) {
  stringstream s(str);
  string word;
  int count = 0;
  while (s >> word) count++;
  return count;
}
inline bool IsLowerCharacter(char c) { return c >= 'a' && c <= 'z'; }
int main() {
  string ham;
  cin >> ham;
  int numOfB = 0, numOfS = 0, numOfC = 0;
  for (int i = 0; i < ham.length(); i++) {
    if (ham[i] == 'B')
      numOfB++;
    else if (ham[i] == 'S')
      numOfS++;
    else if (ham[i] == 'C')
      numOfC++;
  }
  int nB, nS, nC;
  int pB, pS, pC;
  cin >> nB >> nS >> nC;
  cin >> pB >> pS >> pC;
  long long r;
  cin >> r;
  long long num = 0;
  while (true) {
    if (nB - numOfB < 0 || nS - numOfS < 0 || nC - numOfC < 0) break;
    if (nB - numOfB >= 0)
      nB -= numOfB;
    else
      break;
    if (nS - numOfS >= 0)
      nS -= numOfS;
    else
      break;
    if (nC - numOfC >= 0)
      nC -= numOfC;
    else
      break;
    num++;
  }
  while ((nB || nS || nC) && numOfC && numOfB && numOfS) {
    long long price = 0;
    if (nB < numOfB) {
      price += (numOfB - nB) * pB;
      nB = 0;
    } else {
      nB -= numOfB;
    }
    if (nS < numOfS) {
      price += (numOfS - nS) * pS;
      nS = 0;
    } else {
      nS -= numOfS;
    }
    if (nC < numOfC) {
      price += (numOfC - nC) * pC;
      nC = 0;
    } else {
      nC -= numOfC;
    }
    if (price <= r) {
      r -= price;
      num++;
    } else
      break;
  }
  long long priceOfoneHam = pB * numOfB + pS * numOfS + pC * numOfC;
  num += r / priceOfoneHam;
  cout << num;
  return 0;
}
