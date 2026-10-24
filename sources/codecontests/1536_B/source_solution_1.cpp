#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ld long double 
#define pii pair<int, int>
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rfor(i, b, a) for(ll i = b; i >= a; i--)
#define X first
#define Y second
#define pb push_back
#define play {ios_base::sync_with_stdio(false);}
#define tennis {cin.tie(NULL); cout.tie(NULL);}
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define vsz(x) ((long long) x.size())
#define arrout(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define arrin(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define debug(x) cout << '>' << #x << ':' << x << endl;
//const ll mod = 1e9 + 7;
 
//dont stop trying :)
 
template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}
 
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
	bool first = true;
	os << "[";
	for(unsigned int i = 0; i < v.size(); i++)
	{
		if(!first)
			os << ", ";
		os << v[i];
		first = false;
	}
	return os << "]";
}

template<typename T>
void outputVector(vector<T> v) {
    cout << v.size() << '\n';
    for(auto x : v) cout << x << " ";
    cout << '\n';
}
 
ll n, m, k;
const ll template_size_array = 1e6 + 1377;
ll a[template_size_array];
ll b[template_size_array];
ll c[template_size_array];
string s, t;
int cnt = 0;

char ret(int i) {
	return 'a' + i;
}


string mex() {
	queue<string> q;
	string res = "";
	rep(i, 0, 26) {
		q.push(res + ret(i));
		if(s.find(ret(i)) == string::npos) {
			return res + ret(i);
		}
	}

	while(q.size()) {
		string temp = q.front();
		q.pop();
		rep(i, 0, 26) {
			q.push(temp + ret(i));
			if(s.find(temp + ret(i)) == string::npos) {
				return temp + ret(i);
			}
			q.push(temp + ret(i));
		}
	}
}

void solve(int tc = 0) {
	cin >> n;
	cin >> s;

	cout << mex() << endl;

}
 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	#endif

	play tennis;
	cout << setprecision(12) << fixed;	
	
	int tc = 1;
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) solve(tt);
	return 0;
}
