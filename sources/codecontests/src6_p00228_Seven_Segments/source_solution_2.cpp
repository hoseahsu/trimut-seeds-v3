#include <iostream>
using namespace std;

const bool num[10][7] =  {{0,1,1,1,1,1,1},
					{0,0,0,0,1,1,0},
					{1,0,1,1,0,1,1},
					{1,0,0,1,1,1,1},
					{1,1,0,0,1,1,0},
					{1,1,0,1,1,0,1},
					{1,1,1,1,1,0,1},
					{0,1,0,0,1,1,1},
					{1,1,1,1,1,1,1},
					{1,1,0,1,1,1,1}};

bool now[7];
bool dif[7];
void init()
{
	for(int i=0;i<7;i++){
		now[i] = 0;
		dif[i] = 0;
	}
}
void show()
{
	for(int i=0;i<7;i++){
		cout << dif[i];
	}
	cout << endl;
}
void solve(int m)
{
	for(int i=0;i<7;i++){
		if(now[i]!=num[m][i]){
			dif[i] = 1;
		}else{
			dif[i] = 0;
		}
		now[i] = num[m][i];
	}
}
int main()
{
	int n;
	while(cin >> n){
		if(n<0)
			break;
		init();
		int m;
		for(int i=0;i<n;i++){
			cin >> m;
			solve(m);
			show();
		}
	}
	return 0;
}