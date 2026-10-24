#include <iostream>
using namespace std;
string a, b, c;
int main()
{
	cin >> a >> b >> c;
	if(a[a.size() - 1] == b[0] && b[b.size() - 1] == c[0]){
		cout << "YES";
	}else {
		cout << "NO";
	}
    return 0;
}
