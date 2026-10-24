#include <bits/stdc++.h>

#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 100;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    while (s.size() > 3) {
        const int N = s.size();
        string next;
        vector<int> num(3, 0);
        int star = 0;
        for (int i = 0; i < N; i++) {
            if (i < N - 2) {
                if (s.substr(i, 3) == "ABC") {
                    next.push_back('*');
                    star++;
                    i += 2;
                } else {
                    next.push_back(s[i]);
                    num[s[i] - 'A']++;
                }
            } else {
                next.push_back(s[i]);
                num[s[i] - 'A']++;
            }
        }
        int zero = 0;
        char zerochar = '%';
        for (int i = 0; i < 3; i++) {
            if (num[i] == 0) {
                zero++;
                zerochar = 'A' + i;
            }
        }
        if (star > 0 and zero == 1) {
            s = next;
            for (char& c : s) {
                if (c == '*') {
                    c = zerochar;
                }
            }
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s == "ABC") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}