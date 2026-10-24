#include <bits/stdc++.h>
#define INT(name) int name; scanf("%d",&name);
#define VINT(name,n) vector<int> name(n); for(int i = 0;i < n;i++) scanf("%d",&name[i]);

using namespace std;

int main(int argc, char const *argv[]){
	vector<unsigned long long> data(4000);
	vector<int> f(4000);
	int i;
	long long a,b,c;
	bool check;

	cin >> i;
	while(i){

		for(int j = 0;j < 4000;j++){
			data[j] = 0;
		}


		for(int j = 0;j < i;j++){
			cin >> a >> b >> c;
			data[a - 1] += (long long)b * c;
			f[j] = a - 1;
		}


		check = false;

		for(int j = 0;j < i;j++){
			if(data[f[j]] >= 1000000){
				printf("%d\n",f[j] + 1);
				data[f[j]] = 0;
				check = true;
			}
		}

		if(!check) printf("NA\n");

		cin >> i;
	}

	return 0;
}