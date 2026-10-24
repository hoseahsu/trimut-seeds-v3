#include <bits/stdc++.h>
#define M 1000000007
#define INF (int)1e9
#define N_BIG 1e5

 
typedef long long ll;
 
using namespace std;
vector<int> isPrime_(N_BIG+1, true);
void findPrime(int n){
	for(int i = 2; i*i <= n; i++){
		if(isPrime_[i]){
			for(int j = i*i; j <= n; j+=i)
				isPrime_[j] = false;
		}
	}
	return;
}
void printV(vector<int> &v){
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	return;
}
void inputV(vector<int> &v){
	for(int i=0;i<v.size();i++){
		cin >> v[i];
	}
}
bool isPrime(long long n)
{
    int skip=0;
    if(n<2)
        return false;
    else if(n==2)
        return true;
    long long limit=sqrt(n);
    if(n%2==0)
        return false;
	for(int j=3; j<=limit; j+=2){
		if(n%j==0)
			return false;
	}
    return true;
}
int interact(int i, int j){
	cout << "? " << i+1 << " " << j+1 << "\n";
	int x;
	cin >> x;
	return x;
}
vector<int> factors(int n){
	vector<int> v;
	for(int i = 1; i*i <= n; i++){
		if(n % i == 0){
			v.push_back(i);
			if(i != n/i)
				v.push_back(n/i);
		}
	}
 
	return v;
}

bool gcdsum(ll n){
	ll m = n;
	ll sum = 0;
	while(m>0){
		int x = m%10;
		m/=10;
		sum+=x;
	}
	for(int i=2; i<= sum; i++){
		if(sum%i==0 && n%i==0){
			return true;
		}
	}
	return false;
}


void test_case(){
	ll n;
	cin >> n;
	while(true){
		if(gcdsum(n)){
			cout << n << endl;
			return;
		}
		n++;
	}


}
 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
 
	ll TT;
    cin >> TT;
 
    
 
	for(ll i = 0; i < TT; i++){
		test_case();
	}
	
	return 0;
}