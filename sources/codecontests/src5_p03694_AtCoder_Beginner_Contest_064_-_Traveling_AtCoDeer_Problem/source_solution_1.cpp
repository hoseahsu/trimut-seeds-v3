#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];

int main()
{
	cin >> n;
	int i;
	for(i=0;i<n;i++)
		cin >> arr[i];
	sort(arr,arr+n);
	cout << arr[n-1]-arr[0] << endl;
}